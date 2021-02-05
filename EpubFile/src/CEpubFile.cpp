#include "../CEpubFile.h"
#include "../../DesktopEditor/common/Directory.h"
#include "../../OfficeUtils/src/OfficeUtils.h"
#include "../../DesktopEditor/xml/include/xmlutils.h"
#include "../../HtmlFile2/htmlfile2.h"
#include "src/CBookInfo.h"

#include <iostream>
#include <string>

// Заменяет в строке s все символы s1 на s2
static void replace_all(std::wstring& s, const std::wstring& s1, const std::wstring& s2)
{
    size_t pos = s.find(s1);
    size_t l = s2.length();
    while(pos != std::string::npos)
    {
        s.replace(pos, s1.length(), s2);
        pos = s.find(s1, pos + l);
    }
}

CEpubFile::CEpubFile()
{
}

CEpubFile::~CEpubFile()
{
}

HRESULT CEpubFile::IsEpubFile(const std::wstring& sFileName)
{
    if (NSFile::GetFileExtention(sFileName) != L"epub")
        return S_FALSE;

    COfficeUtils oOfficeUtils;

    m_sFileName = sFileName;
    return oOfficeUtils.IsFileExistInArchive(sFileName, L"META-INF/container.xml") == S_OK ? S_OK : S_FALSE;
}

void CEpubFile::SetTempDirectory(const std::wstring& sTempDir)
{
    m_sTempDir = sTempDir;
}

HRESULT CEpubFile::Convert(const std::wstring& sInputFile, const std::wstring& sOutputFile, bool bIsOutCompress)
{
    COfficeUtils oOfficeUtils;

    wchar_t* password = NULL;
    if (oOfficeUtils.ExtractToDirectory(sInputFile, m_sTempDir.c_str(), password, 1) != S_OK)
        return S_FALSE;

    std::wstring sFileContent;
    std::wstring sContent;
    if(!NSFile::CFileBinary::ReadAllTextUtf8(m_sTempDir + L"/container.xml", sFileContent))
        return S_FALSE;
    size_t nContent = sFileContent.find(L"full-path");
    if(nContent != std::wstring::npos)
    {
        nContent += 11;
        sContent = sFileContent.substr(nContent, sFileContent.find(L'\"', nContent) - nContent);
        size_t posLastSlash = sContent.rfind(L'/');
        if (posLastSlash != std::wstring::npos)
            sContent = sContent.substr(posLastSlash + 1);
    }
    sContent = m_sTempDir + (sContent.empty() ? L"/content.opf" : L'/' + sContent);


    XmlUtils::CXmlLiteReader oXmlLiteReader;
    if (oXmlLiteReader.FromFile(sContent))
    {
        oXmlLiteReader.ReadNextNode();
        int nParentDepth = oXmlLiteReader.GetDepth();
        while (oXmlLiteReader.ReadNextSiblingNode(nParentDepth))
        {
            std::wstring sName = oXmlLiteReader.GetName();
            size_t nDot = sName.find(L':');
            if(nDot != std::wstring::npos)
                sName.erase(0, nDot + 1);
            if (sName == L"metadata")
            {
                m_oBookInfo.ReadInfo(oXmlLiteReader);
//                #ifdef _DEBUG
//                    m_oBookInfo.ShowInfo();
//                #endif
            }
            else if (sName == L"manifest")
            {
                int _nParentDepth = oXmlLiteReader.GetDepth();
                while (true)
                {
                    CBookItem oItem;
                    if (oItem.ReadItem(oXmlLiteReader, _nParentDepth))
                        m_mapRefs.insert(std::make_pair(oItem.GetID(), oItem));
                    else
                        break;
                }
            }
            else if (sName == L"spine")
            {
                int _nParentDepth = oXmlLiteReader.GetDepth();
                while (true)
                {
                    CBookContentItem oContentItem;
                    if (oContentItem.ReadContentItem(oXmlLiteReader, _nParentDepth))
                        m_arContents.push_back(oContentItem);
                    else
                        break;
                }
            }
        }
    }
    else
        return S_FALSE;

    /*
    if (!oXmlLiteReader.FromFile(m_sTempDir + L"/toc.ncx"))
        return S_FALSE;

    oXmlLiteReader.ReadNextNode();
    m_oToc.ReadToc(oXmlLiteReader);
//        #ifdef _DEBUG
//            m_oToc.ShowToc();
//        #endif
    */

    CHtmlFile2 oFile;
    CHtmlParams oFileParams;

    oFileParams.SetAuthors(m_oBookInfo.GetCreators());
    oFileParams.SetGenres(m_oBookInfo.GetSubjects());
    oFileParams.SetTitle(m_oBookInfo.GetTitle());
    oFileParams.SetDate(m_oBookInfo.GetDate());
    oFileParams.SetDescription(m_oBookInfo.GetDescriptions());
    oFileParams.SetPageBreakBefore(true);

    std::wstring sDocxFileTempDir = m_sTempDir + L"/tmp";
    NSDirectory::CreateDirectory(sDocxFileTempDir);
    oFile.SetTmpDirectory(sDocxFileTempDir);

    std::vector<std::wstring> arFiles;
    for (const CBookContentItem& oContent : m_arContents)
    {
        std::wstring sFile = m_mapRefs[oContent.m_sID].GetRef();
        replace_all(sFile, L"%20", L" ");
        arFiles.push_back(m_sTempDir + L"/" + sFile);
    }

#ifdef _DEBUG
    std::wcout << L"---The conversion process from Epub to Docx...---" << std::endl;
#endif

    std::wstring sOutputDir = m_sTempDir + L"/res";
    if (!bIsOutCompress)
        sOutputDir = sOutputFile;

    NSDirectory::CreateDirectory(sOutputDir);
    HRESULT hRes = oFile.OpenBatchHtml(arFiles, sOutputDir, &oFileParams);
    if (bIsOutCompress && S_OK == hRes)
        oOfficeUtils.CompressFileOrDirectory(sOutputDir, sOutputFile);

#ifdef _DEBUG
    std::wcout << L"---" << (S_OK == hRes ? L"Successful" : L"Failed") << L" conversion of Epub to Docx---" << std::endl;
#endif

    return hRes;
}

void CEpubFile::Clear()
{
    m_sFileName .clear();
    m_sTempDir  .clear();
    m_oBookInfo .Clear();
    m_mapRefs   .clear();
    m_oToc      .Clear();
    m_arContents.clear();
}

void CEpubFile::ShowMap()
{
    std::cout << "-----MAP-----" << std::endl;
    for (const CBookContentItem& oItem : m_arContents)
        std::wcout << oItem.m_sID << L" - " << m_mapRefs[oItem.m_sID].GetRef() << std::endl;
}

HRESULT CEpubFile::FromHtml(const std::wstring& sSrc, const std::wstring& sDstFile)
{
    NSDirectory::CreateDirectory(m_sTempDir + L"/META-INF");
    NSDirectory::CreateDirectory(m_sTempDir + L"/OEBPS");

    NSFile::CFileBinary oMimeType;
    if (oMimeType.CreateFileW(m_sTempDir + L"/mimetype"))
    {
        oMimeType.WriteStringUTF8(L"application/epub+zip");
        oMimeType.CloseFile();
    }

    NSFile::CFileBinary oContainerXml;
    if (oContainerXml.CreateFileW(m_sTempDir + L"/META-INF/container.xml"))
    {
        oContainerXml.WriteStringUTF8(L"<?xml version=\"1.0\" encoding=\"UTF-8\"?><container version=\"1.0\" xmlns=\"urn:oasis:names:tc:opendocument:xmlns:container\"><rootfiles><rootfile full-path=\"OEBPS/content.opf\" media-type=\"application/oebps-package+xml\"/></rootfiles></container>");
        oContainerXml.CloseFile();
    }

    NSFile::CFileBinary oContentOpf;
    if (oContentOpf.CreateFileW(m_sTempDir + L"/OEBPS/content.opf"))
    {
        // index.html
        NSFile::CFileBinary::Copy(sSrc + L"/doct_unpacked/index.html", m_sTempDir + L"/OEBPS/index.html");
        NSDirectory::CopyDirectory(sSrc + L"/doct_unpacked/images", m_sTempDir + L"/OEBPS/images");
        // cover.html
        bool bCoverFromImg1 = NSFile::CFileBinary::Exists(sSrc + L"/doct_unpacked/images/img1.png");

        oContentOpf.WriteStringUTF8(L"<?xml version=\"1.0\" encoding=\"UTF-8\"?><package xmlns=\"http://www.idpf.org/2007/opf\" version=\"2.0\" unique-identifier=\"book_uuid\"><metadata xmlns:dc=\"http://purl.org/dc/elements/1.1/\">");
        // metadata
        std::wstring sCoreXml;
        bool bWasIdentifier = false;
        XmlUtils::CXmlLiteReader oCoreReader;
        if (NSFile::CFileBinary::ReadAllTextUtf8(sSrc + L"/docx_unpacked/docProps/core.xml", sCoreXml))
        {
            oCoreReader.FromString(sCoreXml);
            oCoreReader.ReadNextNode();
            int nDeath = oCoreReader.GetDepth();
            while (oCoreReader.ReadNextSiblingNode(nDeath))
            {
                if (oCoreReader.GetNamespacePrefix() == L"dc")
                {
                    if (oCoreReader.GetName() == L"dc:identifier")
                        bWasIdentifier = true;
                    oContentOpf.WriteStringUTF8(oCoreReader.GetOuterXml());
                }
            }
        }
        if (!bWasIdentifier)
        {
            std::wstring sUUID = NSDirectory::CreateDirectoryWithUniqueName(m_sTempDir);
            NSDirectory::DeleteDirectory(sUUID);
            sUUID.erase(0, sUUID.find_last_of(L"\\/") + 1);
            oContentOpf.WriteStringUTF8(L"<dc:identifier id=\"book_uuid\" opf:scheme=\"UUID\">urn:uuid:");
            oContentOpf.WriteStringUTF8(sUUID);
            oContentOpf.WriteStringUTF8(L"</dc:identifier>");
        }
        if (bCoverFromImg1)
            oContentOpf.WriteStringUTF8(L"<meta name=\"cover\" content=\"img1.png\"/>");
        // manifest
        oContentOpf.WriteStringUTF8(L"</metadata><manifest><item id=\"ncx\" href=\"toc.ncx\" media-type=\"application/x-dtbncx+xml\"/>");
        std::vector<std::wstring> arFiles = NSDirectory::GetFiles(m_sTempDir + L"/OEBPS/images");
        for (const std::wstring& sFileName : arFiles)
        {
            std::wstring sName = NSFile::GetFileName(sFileName);
            oContentOpf.WriteStringUTF8(L"<item id=\"" + sName + L"\" href=\"images/" + sName + L"\" media-type=\"image/png\"/>");
        }
        oContentOpf.WriteStringUTF8(L"<item id=\"index\" href=\"index.html\" media-type=\"application/xhtml+xml\"/>");
        if (bCoverFromImg1)
            oContentOpf.WriteStringUTF8(L"<item id=\"cover\" href=\"cover.html\" media-type=\"application/xhtml+xml\"/>");
        // spine
        oContentOpf.WriteStringUTF8(L"</manifest><spine toc=\"ncx\">");
        if (bCoverFromImg1)
            oContentOpf.WriteStringUTF8(L"<itemref idref=\"cover\"/>");
        // guide
        oContentOpf.WriteStringUTF8(L"<itemref idref=\"index\"/></spine><guide>");
        if (bCoverFromImg1)
            oContentOpf.WriteStringUTF8(L"<reference type=\"cover\" title=\"Cover\" href=\"cover.html\"/>");
        oContentOpf.WriteStringUTF8(L"</guide></package>");
        oContentOpf.CloseFile();
    }

    COfficeUtils oOfficeUtils;
    return oOfficeUtils.CompressFileOrDirectory(m_sTempDir, sDstFile);
}

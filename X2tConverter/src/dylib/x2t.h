/*
 * (c) Copyright Ascensio System SIA 2010-2019
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at 20A-12 Ernesta Birznieka-Upisha
 * street, Riga, Latvia, EU, LV-1050.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */
#ifndef _BUILD_FILE_X2T_DYLIB_
#define _BUILD_FILE_X2T_DYLIB_

#ifdef BUILD_X2T_AS_LIBRARY_DYLIB

#ifdef _MSC_VER
#define X2T_DECL __declspec(dllexport)
#else
#define X2T_DECL __attribute__((visibility("default")))
#endif

#else

#ifdef _MSC_VER
#define X2T_DECL __declspec(dllimport)
#else
#define X2T_DECL
#endif

#endif

#if !defined(_WIN32) && !defined (_WIN64)
    #define x2tchar char
#else
    #define x2tchar wchar_t
#endif

namespace NSX2T
{
    X2T_DECL int Convert(int argc, x2tchar *argv[]);
}

#endif //_BUILD_FILE_X2T_DYLIB_

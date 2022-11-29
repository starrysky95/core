﻿/*
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

#include "../../../PptFile/Enums/RecordType.cpp"
#include "../../../PptFile/Reader/ReadStructures.cpp"
#include "../../../PptFile/Reader/RoundTripExtractor.cpp"
#include "../../../PptFile/Reader/PPTDocumentInfoOneUser.cpp"
#include "../../../PptFile/Reader/Records.cpp"
#include "../../../PptFile/Reader/PPTFileReader.cpp"
#include "../../../PptFile/Reader/SlidePersist.cpp"

#include "../../../PptFile/PPTXWriter/Converter.cpp"
#include "../../../PptFile/PPTXWriter/ShapeWriter.cpp"
#include "../../../PptFile/PPTXWriter/TableWriter.cpp"
#include "../../../PptFile/PPTXWriter/TxBodyConverter.cpp"
#include "../../../PptFile/PPTXWriter/BulletsConverter.cpp"

#include "../../../PptFile/Records/Drawing/ArtBlip.cpp"
#include "../../../PptFile/Records/Drawing/ShapeContainer.cpp"
#include "../../../PptFile/Records/Animations/TimeVariant.cpp"
#include "../../../PptFile/Records/BlipEntityAtom.cpp"

#include "../../../PptFile/Drawing/Element.cpp"
#include "../../../PptFile/Drawing/Elements.cpp"
#include "../../../PptFile/Drawing/Layout.cpp"
#include "../../../PptFile/Drawing/Slide.cpp"
#include "../../../PptFile/Drawing/TextStructures.cpp"
#include "../../../PptFile/Drawing/TextAttributesEx.cpp"
#include "../../../PptFile/Drawing/Theme.cpp"

#include "../../../PptFile/Converter/Animation/AnimationParser.cpp"
#include "../../../PptFile/Converter/Animation/Animation_1995.cpp"
#include "../../../PptFile/Converter/Animation/TimingUtils.cpp"
#include "../../../PptFile/Converter/Animation/Timing_1995.cpp"
#include "../../../PptFile/Converter/Animation/Timing_2010.cpp"
#include "../../../PptFile/Converter/Animation/hashcode10.cpp"
#include "../../../PptFile/Converter/Animation/intermediate_anim.cpp"
#include "../../../PptFile/Converter/timing.cpp"
#include "../../../PptFile/Converter/transition.cpp"

#include "../../../PptFile/Records/Animations/AnimationInfoAtom.cpp"
#include "../../../PptFile/Records/Animations/AnimationInfoContainer.cpp"
#include "../../../PptFile/Records/Animations/BuildAtom.cpp"
#include "../../../PptFile/Records/Animations/BuildListSubContainer.cpp"
#include "../../../PptFile/Records/Animations/ChartBuildAtom.cpp"
#include "../../../PptFile/Records/Animations/ChartBuildContainer.cpp"
#include "../../../PptFile/Records/Animations/ClientVisualElementContainer.cpp"
#include "../../../PptFile/Records/Animations/DiagramBuildAtom.cpp"
#include "../../../PptFile/Records/Animations/DiagramBuildContainer.cpp"
#include "../../../PptFile/Records/Animations/ExtTimeNodeContainer.cpp"
#include "../../../PptFile/Records/Animations/HashCode10Atom.cpp"
#include "../../../PptFile/Records/Animations/LevelInfoAtom.cpp"
#include "../../../PptFile/Records/Animations/ParaBuildAtom.cpp"
#include "../../../PptFile/Records/Animations/ParaBuildContainer.cpp"
#include "../../../PptFile/Records/Animations/ParaBuildLevel.cpp"
#include "../../../PptFile/Records/Animations/SubEffectContainer.cpp"
#include "../../../PptFile/Records/Animations/TimeAnimateBehaviorAtom.cpp"
#include "../../../PptFile/Records/Animations/TimeAnimateBehaviorContainer.cpp"
#include "../../../PptFile/Records/Animations/TimeAnimateColor.cpp"
#include "../../../PptFile/Records/Animations/TimeAnimateColorBy.cpp"
#include "../../../PptFile/Records/Animations/TimeAnimationValueAtom.cpp"
#include "../../../PptFile/Records/Animations/TimeAnimationValueListContainer.cpp"
#include "../../../PptFile/Records/Animations/TimeAnimationValueListEntry.cpp"
#include "../../../PptFile/Records/Animations/TimeBehaviorAtom.cpp"
#include "../../../PptFile/Records/Animations/TimeBehaviorContainer.cpp"
#include "../../../PptFile/Records/Animations/TimeColorBehaviorAtom.cpp"
#include "../../../PptFile/Records/Animations/TimeColorBehaviorContainer.cpp"
#include "../../../PptFile/Records/Animations/TimeCommandBehaviorAtom.cpp"
#include "../../../PptFile/Records/Animations/TimeCommandBehaviorContainer.cpp"
#include "../../../PptFile/Records/Animations/TimeConditionAtom.cpp"
#include "../../../PptFile/Records/Animations/TimeConditionContainer.cpp"
#include "../../../PptFile/Records/Animations/TimeEffectBehaviorAtom.cpp"
#include "../../../PptFile/Records/Animations/TimeEffectBehaviorContainer.cpp"
#include "../../../PptFile/Records/Animations/TimeIterateDataAtom.cpp"
#include "../../../PptFile/Records/Animations/TimeModifierAtom.cpp"
#include "../../../PptFile/Records/Animations/TimeMotionBehaviorAtom.cpp"
#include "../../../PptFile/Records/Animations/TimeMotionBehaviorContainer.cpp"
#include "../../../PptFile/Records/Animations/TimeNodeAtom.cpp"
#include "../../../PptFile/Records/Animations/TimePropertyList4TimeBehavior.cpp"
#include "../../../PptFile/Records/Animations/TimePropertyList4TimeNodeContainer.cpp"
#include "../../../PptFile/Records/Animations/TimeRotationBehaviorAtom.cpp"
#include "../../../PptFile/Records/Animations/TimeRotationBehaviorContainer.cpp"
#include "../../../PptFile/Records/Animations/TimeScaleBehaviorAtom.cpp"
#include "../../../PptFile/Records/Animations/TimeScaleBehaviorContainer.cpp"
#include "../../../PptFile/Records/Animations/TimeSequenceDataAtom.cpp"
#include "../../../PptFile/Records/Animations/TimeSetBehaviorAtom.cpp"
#include "../../../PptFile/Records/Animations/TimeSetBehaviorContainer.cpp"
#include "../../../PptFile/Records/Animations/TimeStringListContainer.cpp"
#include "../../../PptFile/Records/Animations/TimeVariant4Behavior.cpp"
#include "../../../PptFile/Records/Animations/VisualPageAtom.cpp"
#include "../../../PptFile/Records/Animations/VisualShapeAtom.cpp"
#include "../../../PptFile/Records/Animations/VisualShapeChartElementAtom.cpp"
#include "../../../PptFile/Records/Animations/VisualShapeGeneralAtom.cpp"
#include "../../../PptFile/Records/Animations/VisualSoundAtom.cpp"
#include "../../../PptFile/Records/BlipCollection9Container.cpp"
#include "../../../PptFile/Records/BookmarkEntityAtom.cpp"
#include "../../../PptFile/Records/BookmarkSeedAtom.cpp"
#include "../../../PptFile/Records/BuildAtom.cpp"
#include "../../../PptFile/Records/CFMasks.cpp"
#include "../../../PptFile/Records/CString.cpp"
#include "../../../PptFile/Records/ColorSchemeAtom.cpp"
#include "../../../PptFile/Records/Comment10Container.cpp"
#include "../../../PptFile/Records/CurrentUserAtom.cpp"
#include "../../../PptFile/Records/DocInfoListContainer.cpp"
#include "../../../PptFile/Records/DocProgTagsContainer.cpp"
#include "../../../PptFile/Records/DocRoutingSlipAtom.cpp"
#include "../../../PptFile/Records/DocumentAtom.cpp"
#include "../../../PptFile/Records/DocumentRecords.cpp"
#include "../../../PptFile/Records/DocumentTextInfo.cpp"
#include "../../../PptFile/Records/Drawing/BlipStoreContainer.cpp"
#include "../../../PptFile/Records/Drawing/BlipStoreEntry.cpp"
#include "../../../PptFile/Records/Drawing/ChildAnchor.cpp"
#include "../../../PptFile/Records/Drawing/ClientAnchor.cpp"
#include "../../../PptFile/Records/Drawing/DrawingContainer.cpp"
#include "../../../PptFile/Records/Drawing/DrawingGroup.cpp"
#include "../../../PptFile/Records/Drawing/DrawingRecord.cpp"
#include "../../../PptFile/Records/Drawing/GroupShape.cpp"
#include "../../../PptFile/Records/Drawing/Shape.cpp"
#include "../../../PptFile/Records/Drawing/ShapeProperties.cpp"
#include "../../../PptFile/Records/Drawing/TextBox.cpp"
#include "../../../PptFile/Records/EndDocument.cpp"
#include "../../../PptFile/Records/ExCDAudioContainer.cpp"
#include "../../../PptFile/Records/ExControlAtom.cpp"
#include "../../../PptFile/Records/ExHyperlinkAtom.cpp"
#include "../../../PptFile/Records/ExMIDIAudioContainer.cpp"
#include "../../../PptFile/Records/ExMediaAtom.cpp"
#include "../../../PptFile/Records/ExObjListAtom.cpp"
#include "../../../PptFile/Records/ExObjListContainer.cpp"
#include "../../../PptFile/Records/ExObjRefAtom.cpp"
#include "../../../PptFile/Records/ExOleEmbedAtom.cpp"
#include "../../../PptFile/Records/ExOleLinkAtom.cpp"
#include "../../../PptFile/Records/ExOleObjAtom.cpp"
#include "../../../PptFile/Records/ExVideoContainer.cpp"
#include "../../../PptFile/Records/ExWAVAudioEmbeddedContainer.cpp"
#include "../../../PptFile/Records/ExWAVAudioLinkContainer.cpp"
#include "../../../PptFile/Records/FontCollection10Container.cpp"
#include "../../../PptFile/Records/FontEmbedFlags10Atom.cpp"
#include "../../../PptFile/Records/FontEntityAtom.cpp"
#include "../../../PptFile/Records/GridSpacing10Atom.cpp"
#include "../../../PptFile/Records/GuideAtom.cpp"
#include "../../../PptFile/Records/HeadersFootersAtom.cpp"
#include "../../../PptFile/Records/InteractiveInfoAtom.cpp"
#include "../../../PptFile/Records/KinsokuAtom.cpp"
#include "../../../PptFile/Records/KinsokuContainer.cpp"
#include "../../../PptFile/Records/KinsokuFollowingAtom.cpp"
#include "../../../PptFile/Records/KinsokuLeadingAtom.cpp"
#include "../../../PptFile/Records/LinkedShape10Atom.cpp"
#include "../../../PptFile/Records/LinkedSlide10Atom.cpp"
#include "../../../PptFile/Records/MasterPersistAtom.cpp"
#include "../../../PptFile/Records/MasterTextPropAtom.cpp"
#include "../../../PptFile/Records/MetafileBlob.cpp"
#include "../../../PptFile/Records/MouseInteractiveInfoContainer.cpp"
#include "../../../PptFile/Records/MouseTextInteractiveInfoAtom.cpp"
#include "../../../PptFile/Records/NamedShowSlidesAtom.cpp"

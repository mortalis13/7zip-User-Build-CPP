#include "StdAfx.h"
#include "../../../Common/MyInitGuid.h"
#include "../Common/ArchiveCommandLine.h"

#include "ArchInfo.h"

// #include <iostream>
// using namespace std;


int getArchRootItems(const UString &fileName) {
  try {
    // std::cout << "--getArchRootItems()--\n";
    
    CCodecs *codecs = new CCodecs;
    CExternalCodecs __externalCodecs;
    __externalCodecs.GetCodecs = codecs;
    __externalCodecs.GetHashers = codecs;
    CCodecs::CReleaser codecsReleaser;
    codecsReleaser.Set(codecs);
    
    codecs->CaseSensitiveChange = false;
    codecs->CaseSensitive = false;
    if (codecs->Load() != S_OK) {
      // std::cout << "Codecs Load ERROR\n";
      return 0;
    }

    CObjectVector<COpenType> types;
    CIntVector excludedFormats;

    UStringVector ArchivePathsSorted;
    ArchivePathsSorted.ClearAndReserve(1);
    ArchivePathsSorted.AddInReserved(fileName);

    UInt64 numVolumes = 0;
    UInt64 numArcs = 0;
    UInt64 totalArcSizes = 0;
    
    for (unsigned arcIndex = 0; arcIndex < ArchivePathsSorted.Size(); arcIndex++) {
      const UString &arcPath = ArchivePathsSorted[arcIndex];
      UInt64 arcPackSize = 0;
      
      NWindows::NFile::NFind::CFileInfo fi;
      if (!fi.Find(us2fs(arcPath))) {
        // std::cout << "NO FILE\n";
        continue;
      }
      
      arcPackSize = fi.Size;
      totalArcSizes += arcPackSize;
      
      COpenOptions options2;
      #ifndef _SFX
      CObjectVector<CProperty>* props = new CObjectVector<CProperty>();
      options2.props = props;
      #endif
      options2.codecs = codecs;
      options2.types = &types;
      options2.excludedFormats = &excludedFormats;
      options2.stdInMode = false;
      options2.stream = NULL;
      options2.filePath = arcPath;
      
      CArchiveLink arcLink;
      HRESULT result = arcLink.Open(options2);
      if (result != S_OK) {
        // std::cout << "===NOK===\n";
        continue;
      }
      else {
        // std::cout << "===OK===\n";
      }
      
      numArcs++;
      numVolumes++;
      
      numVolumes += arcLink.VolumePaths.Size();
      totalArcSizes += arcLink.VolumesSize;
      
      // std::cout << "numVolumes: " << numVolumes << endl;
      // std::cout << "totalArcSizes: " << totalArcSizes << endl;
      // std::cout << "arcLink.VolumePaths.Size: " << arcLink.VolumePaths.Size() << endl;
      
      const CArc &arc = arcLink.Arcs.Back();
      IInArchive *archive = arc.Archive;
      
      UInt32 numItems;
      archive->GetNumberOfItems(&numItems);
      
      // std::cout << "===ITEMS=== [" << numItems << "]\n";
      
      CReadArcItem item;
      UInt32 rootItems = 0;
      for (unsigned i = 0; i < numItems; ++i) {
        HRESULT res2 = arc.GetItem(i, item);
        if (res2 == S_OK) {
          bool inRoot = item.PathParts.Size() == 1;
          if (inRoot) rootItems++;
        }
      }
      
      return rootItems;
    }
  }
  catch(...) {
    return 0;
  }
  
  return 0;
}


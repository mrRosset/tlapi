#pragma once

#include "CRunicCore.h"


namespace TLAPI
{
  struct CQuest;

#pragma pack(1)

  struct CQuestDialog : CRunicCore
  {
    PVOID   unk0;

    CQuest *pCQuest;
  };

#pragma pack()

};

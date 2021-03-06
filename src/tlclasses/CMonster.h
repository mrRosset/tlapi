#pragma once

#include "CCharacter.h"

namespace TLAPI
{

#pragma pack(1)

  // Size?: 6D4h
  //
  struct CMonster: CCharacter
  {
    u32     stance;     // @65C: Pet: 2 Defensive, 1 Aggresive, 0 Passive     write_code@:0549627

    float   unk18[2];

    CList<PVOID>        listParticleAnimationTrigger;   // Type: CCharacter::CParticleAnimationTrigger

    u32     unk19[10];        // 0,0FFFFFFFFh,6 dup(   0),   7, 96h

    float   unk20;            // 60.0

  
    // 
    // Function hooks

    // Monster Get Character Close
    EVENT_DECL(CMonster, void, MonsterGetCharacterClose,
      (CCharacter* &, CMonster*, u32, float, bool&),
      ((CCharacter* &)e->retval, (CMonster*)e->_this, Pz[0], *(float*)&Pz[1], e->calloriginal));

    // Monster Process AI
    EVENT_DECL(CMonster, void, MonsterProcessAI,
      (CMonster*, float, u32, bool&),
      ((CMonster*)e->_this, *(float*)&Pz[0], Pz[1], e->calloriginal));

    // Monster Process AI
    EVENT_DECL(CMonster, void, MonsterProcessAI2,
      (CMonster*, float, CLevel*, u32, bool&),
      ((CMonster*)e->_this, *(float*)&Pz[0], (CLevel*)Pz[1], Pz[2], e->calloriginal));

    // Monster Process AI
    EVENT_DECL(CMonster, void, MonsterProcessAI3,
      (CMonster*, u32, bool&),
      ((CMonster*)e->_this, Pz[0], e->calloriginal));

    // Monster Idle
    EVENT_DECL(CMonster, void, MonsterIdle,
      (CMonster*, float, bool&),
      ((CMonster*)e->_this, *(float*)&Pz[0], e->calloriginal));

  };

#pragma pack()

};
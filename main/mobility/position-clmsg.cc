/*
 * Copyright (c) 2008 Regents of the SIGNET lab, University of Padova.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University of Padova (SIGNET lab) nor the 
 *    names of its contributors may be used to endorse or promote products 
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED 
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR 
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include"position-clmsg.h"
#include<assert.h>
#include<iostream>

ClMessage_t CLMSG_POSITION_GET_DIST;



ClMsgPositionGetDist::ClMsgPositionGetDist(nsaddr_t i, nsaddr_t j)
  :     
    ClMessage(CLMSG_POSITION_VERBOSITY, CLMSG_POSITION_GET_DIST),
    dist(0), 
    valid(false), 
    id1(i), 
    id2(j)
{
//   std::cerr << __PRETTY_FUNCTION__ 
// 	    << " id1=" <<id1
// 	    << " id2=" <<id2
// 	    << " valid=" <<valid
// 	    << " type=" <<type()
// 	    << " destType=" <<getDestType()
// 	    << " dest=" <<getDest()
//        << std::endl;
}




ClMessage* ClMsgPositionGetDist::copy()
{
  // Supporting only synchronous messages!!!
  assert(0);
}


void ClMsgPositionGetDist::returnDist(double d)
{
  if (valid == true)
    {
      // dist was already set by somebody else!!!
      valid = false;
    }
  else
    {
      dist = d;
      valid = true;
    }
  
}

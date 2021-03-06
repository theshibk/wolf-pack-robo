// -*-c++-*-

/*!
  \file bhv_hunt.cpp
  \brief advanced shoot planning and behavior.
*/


/////////////////////////////////////////////////////////////////////

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "bhv_hunt.h"

#include <rcsc/common/logger.h>
#include <rcsc/player/player_agent.h>
#include <rcsc/player/debug_client.h>
#include <rcsc/player/world_model.h>

#include "neck_turn_to_goalie_or_scan.h"

#include "body_smart_kick.h"

namespace rcsc {


/*-------------------------------------------------------------------*/
/*!

*/
bool
Bhv_Hunt::execute( PlayerAgent * agent )
{
    std::list<Vector2D> forces;



}

}

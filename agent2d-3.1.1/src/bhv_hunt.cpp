// -*-c++-*-

/*!
  \file bhv_hunt.cpp
  \brief defensive behavior.
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
#include "neck_turn_to_ball.h"
#include "body_go_to_point.h"

#include "body_smart_kick.h"

namespace rcsc {


/*-------------------------------------------------------------------*/
/*!

*/
bool
Bhv_Hunt::execute( PlayerAgent * agent )
{
    std::list<Vector2D> forces;

    //Get force from prey
    Vector2D preyForce = agent->world().ball().rpos(); //Vector to prey
    int preyCo = 1; // for future usee
    forces.push_front(preyForce * preyCo/preyForce.r2()); //1/r^2 relationship


    //    Get forces from team mates
    // PlayerCont * team = agent->world().teammates();
    // for ( PlayerCont::const_iterator tm = team.begin(); tm != team.end(); ++tm ){

    // }

    //Sum up all forces to create resultant vector
    Vector2D * resultant = new Vector2D();
    for ( std::list<Vector2D>::iterator it = forces.begin(); it != forces.end(); ++it ){
        *resultant = *resultant + *it;
    }

   if ( Body_GoToPoint (*resultant, 5, resultant->r()).execute( agent ) ){
       agent->setNeckAction( new Neck_TurnToBall());
       return true;

   }

   return false;
}

}

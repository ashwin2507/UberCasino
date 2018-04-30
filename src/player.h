#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>


#include <boost/thread.hpp>

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.



#include "io.h"

class player
{
   private:
      enum player_state_t {Init,StartHand,Playing,EndHand} m_player_state;
      std::string m_name;
      void manage_state ();
      void lock ();
      void unlock ();
      unsigned int m_dealer_idx;
      std::vector<Dealer> m_dealer_list;
      std::string m_user_event_string;
      boost::uuids::uuid m_current_game_uuid;
      boost::thread *m_timer_thread;
      float m_balance;
      bool m_timer_event;   // timer has expired
      bool m_user_event;    // user typed in something
      bool m_Player_recv;   // data recved
      bool m_Game_recv;     // data recved, the game UID matches
      bool m_Game_recv_idx; // data recved, the player index matches
      bool m_Dealer_recv;   // data recved

      dds_io<Player,PlayerSeq,PlayerTypeSupport_var,PlayerTypeSupport,PlayerDataWriter_var,
             PlayerDataWriter,PlayerDataReader_var,PlayerDataReader> *p_io;
      dds_io<Dealer,DealerSeq,DealerTypeSupport_var,DealerTypeSupport,DealerDataWriter_var,
             DealerDataWriter,DealerDataReader_var,DealerDataReader> *d_io;
      dds_io<Game,GameSeq,GameTypeSupport_var,GameTypeSupport,GameDataWriter_var,
             GameDataWriter,GameDataReader_var,GameDataReader> *g_io;

      std::string to_string ( player_state_t );

   public:
      boost::uuids::uuid m_my_uid;
      Player m_P; // stores the last data
      Dealer m_D; 
      Game   m_G;

      void setName (std::string);
      // There are 3 possible inputs to the dealer
      //    1. timer expiration
      //    2. external data recieved
      //    3. user input
      void timer_expired ();
      bool dealerExists(Dealer d);
      void external_data (Player P);
      void external_data (Dealer D);
      void external_data (Game G);
      void user_input (std::string);
      player ();
      ~player ();
};
#endif


#include "enum_helpers.h"

// PTR is a global.  Horrible hack

void _cb ( UberCasino::Player P )
{
#ifdef DEBUG_PRINT
  std::cout << "\nRECEIVED -- Player" << std::endl;
  boost::uuids::uuid u;
  memcpy(&u, P.uid, 16);
  std::cout << "     uid " << boost::uuids::to_string( u ) << std::endl;
  memcpy(&u, P.game_uid, 16);
  std::cout << " gam_uid " << boost::uuids::to_string( u ) << std::endl;
  std::cout << "    name " << P.name << std::endl;
  std::cout << " balance " << P.balance << std::endl;
  std::cout << "  action  " << to_string ( P.A ) << std::endl;
  std::cout << "-------------------------------------------------------" 
            << std::endl;
#endif
  PTR->external_data ( P );
}
void _cb ( UberCasino::Dealer D )
{
#ifdef DEBUG_PRINT
  std::cout << "RECEIVED -- Dealer" << std::endl;
  boost::uuids::uuid u;
  memcpy(&u, D.uid, 16);
  std::cout << "         uid " << boost::uuids::to_string( u ) << std::endl;
  std::cout << "        name " << D.name << std::endl;
  memcpy(&u, D.game_uid, 16);
  std::cout << "    game_uid " << boost::uuids::to_string( u ) << std::endl;
  std::cout << "-------------------------------------------------------" 
            << std::endl;
#endif
  PTR->external_data ( D );
}
void _cb ( UberCasino::Game G )
{
#ifdef DEBUG_PRINT
  std::cout << "RECEIVED -- Game" << std::endl;
  std::cout << "         gstate " << to_string ( G.gstate ) << std::endl;
  boost::uuids::uuid u;
  memcpy(&u, G.game_uid, 16);
  std::cout << "     game   uid " << boost::uuids::to_string( u ) << std::endl;
  std::cout << "  active player " << G.active_player << std::endl;
  memcpy(&u, G.p[G.active_player].uid, 16);
  std::cout << "    player uuid " << boost::uuids::to_string( u ) << std::endl;
  for (unsigned int i=0;i<UberCasino::MAX_CARDS_PER_PLAYER;i++)
  {
     if ( G.p[G.active_player].cards[i].valid )
     {
        std::cout  << "      " << to_string ( G.p[G.active_player].cards[i].card  )
                   << "      " << to_string ( G.p[G.active_player].cards[i].suite ) 
                  << std::endl;
     }
  }
  std::cout << "    The Dealers Cards:" << std::endl;
  for (unsigned int i=0;i<UberCasino::MAX_CARDS_PER_PLAYER;i++)
  {
     if ( G.dealer_cards[i].valid )
     {
        std::cout  << "      " << to_string ( G.dealer_cards[i].card  )
                   << "      " << to_string ( G.dealer_cards[i].suite ) 
                  << std::endl;
     }
  }

  std::cout << "-------------------------------------------------------" 
            << std::endl;
#endif
  PTR->external_data ( G );
}


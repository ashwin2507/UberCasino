#ifndef ENUM_HELPERS_H
#define ENUM_HELPERS_H
std::string to_string ( UberCasino::player_action_t t )
{
   std::string retval;
   switch ( t )
   {
      case idle:retval="idle";break;
      case hitting:retval="hitting";break; 
      case standing:retval="standing";break;
      case splitting:retval="splitting";break;
      case doubling:retval="doubling";break;
   }
   return retval;
}

std::string to_string ( UberCasino::game_state t )
{
   std::string retval;
   switch ( t )
   {
      case waiting_to_join:retval = "waiting_to_joing";break;
      case waiting:retval = "waiting";break;
      case playing:retval = "playing";break;
      case end_hand:retval = "end_hand";break;
   }
   return retval;
}

std::string to_string ( UberCasino::suite_t t )
{
   std::string retval;
   switch ( t )
   {
     case hearts:retval = "hearts";break;
     case diamonds:retval = "diamonds";break;
     case clubs:retval = "clubs";break;
     case spades:retval = "spades";break;
   }
   return retval;
}

std::string to_string ( UberCasino::card_kind t )
{
   std::string retval;
   switch ( t )
   {
      case ace:retval = "ace";break;
      case two:retval = "two";break;
      case three:retval = "three";break;
      case four:retval = "four";break;
      case five:retval = "five";break;
      case six:retval = "six";break;
      case seven:retval = "seven";break;
      case eight:retval = "eight";break;
      case nine:retval = "nine";break;
      case ten:retval = "ten";break;
      case jack:retval = "jack";break;
      case queen:retval = "queen";break;
      case king:retval = "king";break;
   }
   return retval;
}
#endif

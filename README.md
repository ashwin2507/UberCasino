# UberCasino

DO NOT USE. YET. More changes to come sunday.


To build:

% source ./release.com
% make 

There are a couple of cpp defines that control debug
output:
    DEBUG_PRINT 

Set this in the makefile and recompile

Requirements:
This is a basic, minimal implementation of the blackjack game.
The players are stupid, and stop at 2 cards, the dealer has
a rigged deck and always deals a 10.
The exact requirements for the class assignment have not been implemented, but it should be close enough to get you started.

Source code:
This is a CLI based program, but note that it is event driven.

It should easily map to a gui callbacks

The main programs are Dealer.cpp and Player.cpp.

The top level classes are dealer.cpp and player.cpp.  All OpenSplice
I/O is done in io.h.  io.h is a generic, it is a bit ugly.

There is a home grown state machine implementation in dealer and player.
It will get way too unwieldy if additional functionality is added.  This
is crying out for additional abstractions.

Use Case:

The dealer starts and waits for the user to enter "start" at the command line.
The dealer then sends out a Dealer struct.

The player starts. When it recieves a Dealer struct, it puts it in a list and displays the list.  Provided there is at least one dealer, the user can enter a number corresponding to the dealer.  When selected, the player will then send a Player structure, this is effectively asking if you can join the game.

The dealer waits until the first Player that matches his game_uuid is recieved.
At that point he starts a 20 second timer, and waits for others.  When a Player that matches is recieved, he inserts it into the Dealer and Publishes.

The timer expires, the dealer then starts to deal the cards. First, he deals himself two cards, one face down. For each player, he adds a card, increments the player idx, and waits for the player to respond with a Player record describing what it wants to do.

After all players have been dealt two cards, the dealer turns over his card, and the game exits.



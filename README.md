# blackjack-two
This is a single player blackjack game played against the computer as the dealer.
## folder structure
- src: contains source code files.
- include: contains header files.
- test: contains the source code files required for unit testing which are dependent on the src and include files. Note read setup details about file path of pattern match file (in file).
- README.md
- makefile: can build blackjack-two and unitTests. Note read setup details about the compiler (in file).

## recent updates
- updated to allow Ace card to take value 11 or 1 depending on the situation and the player's choice.
- updated deck.dealCard() to loop to the start of newly shuffled deck after each complete cycle through.

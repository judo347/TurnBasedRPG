# TurnBasedRPG #
With focus on stats and items!

## Todo: ##
### Improvements: ###
- Add wrong input handling (on user inputs), char name.
- Asserts?

### Additional Content: ###
- Create list of monsters
- Attack function that includes roll for dmg and hit chance
- List of loot
- Inventory:
  - Inventory list or file
  - Inventory menu
- Load function
- Save function


## Bugs: ##
- I campMenu() - Crasher når man ikke rykker op eller ned før man trykker enter.

## Initializing Phase ##

### Brainstorm ###
Items. Inventory. Drops. Stats. Menu for changeing items, only 1 per slot, random lines - from text array. 

Some item that makes you go to camp with 100% chance

Clamp-function: max and min of values, and make sure the value is between.

## Phase 1: Start program ##
Notes: New game, load or exit.

You will be asked if you want the start a new game, load a saved one og exit the game.
If new -> fight. if load -> camp. exit -> terminate.

## Phase 2: Fight ##
Notes: .

Here you will face a sudo-randomly generated monster. If you die??? maybe second chance? eller betal med penge??. If you win you get to choose to return to camp or continue to a new fight.

Decribe the fighting, dice, stats.

## Phase 3: Camp ##
Notes: Chance to return to fighting, full hp, manage inventory, save and exit.

If a fight is won the player will get to chose: take on another fight or return to camp. If the player decides to return to camp, a dice will roll. If the player is unlucky he will return to a new fight. 
When the player enters the camp he will be healed to max hp and will be able to save and exit, or manage his inventory.


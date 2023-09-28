# PlatforrmGame
The project consisted of implementing a platform game in ASCII graphics consisting of infinite levels, with the goal of obtaining the highest score. The player controlled the protagonist via keyboard and had to explore the different rooms of the map, facing enemies and collecting artefacts to advance.

Required to implement a platform game in ASCII graphics:
▸ Developed on several levels
▸ Score-based
▸ The protagonist is controlled by keyboard
Legend:
‣ P: character
‣ AA: artefact
‣ @@: enemy
‣ XXXXXX: closed door
‣ " ": open door

RUNNING OF THE GAME
Minimum and mandatory requirements:
▸ The map is explored as the player progresses
▸ There are no goals
▸ The player can go back over the map and find everything exactly as he left it
▸ There must be different types of enemies and different types of artefacts
▸ In order to move from one room to another, it is necessary to take artefacts/defeat enemies
▸ It is possible to find 'powers' to unlock passages leading to artefacts

THE SCORE
▸ The human player controls the protagonist
▸ The protagonist has a life score and hearts; 10 life points correspond to one heart
▸ On the way the protagonist encounters enemies, artefacts and powers
▸ Enemies take away hearts; different types of enemies take away different amounts of hearts
▸ Artifacts increase life
▸ Powers unlock passages leading to artefacts, restore life if you have previously been hit by an enemy and/or open room doors
▸ Enemies are controlled by the computer: they can move and shoot, they can be killed by the protagonist (e.g. by shooting)
▸ The map has a top-down view and is divided into rooms; rooms have multiple entrances/exits (doors)
▸ When the life of the protagonist drops to 0, the game ends

PROJECT SETTING
Constraints:
▸ The map must have ASCII graphics, only the curses/ncurses.h libraries can be used to handle the graphics
▸ The room elements must be managed via dynamic data structures (i.e. insertion and removal)
▸ The project is to be realised using the classes
▸ The project shall be organised in several files

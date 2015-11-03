#Chamber-Crawler 3000
Final Object Oriented Programming project made for University of Waterloo. Developed by Austin Luo and Yi Chen. Do not use this code in your own CS246 project

###How to run
1. 'git clone https://github.com/aluo123/Chamber-Crawler-3000' into a local directory
2. 'make' to compile the code for linux environment
3. Run with './cc3k' with no arguments for random generated levels. Run './cc3k cc3kfloor.txt' to run with pre-generated levels

###Select a Class
|Race | HP | Attack | Defense | Special Effects |
|:---|:---:|:---:|:---:|:---|
|Shade | 125 | 25 | 25 | None|
|Drow | 150 | 25 | 15 | Potions are 1.5 times as effective|
|Vampire | 50 | 25 | 25 | Gains 5 hp per attack, no max health |
|Troll | 120 | 25 | 15 | Heals 5 hp per turn |
|Goblin | 110 | 15 | 20 | Loots 5 gold from every slain enemy |

###How to play
1. To move, type 'no' to move one space north, 'ne' for one space north-east, 'ea' for one space east, 'se' for one space south-east, 'so' for one space south, 'sw' for one space south-west, 'we' for one space west, and 'nw' for one space north-west
2. To attack, type 'a dir' where 'dir' is one of the 8 directions
3. To use a potion, type 'u dir' where 'dir' is one of the 8 directions
4. Walk over gold to pick up gold

###Goal
The goal of the game is to try and get as much gold as possible. The game ends when you complete the 5th level or die.

###Legend
|Symbol|Description|
|:------:|-----------|
| . | Tile |
| + | Door |
| | | Wall |
| # | Passage |
| @ | Player |
| P | Potion |
| G | Gold |
| \ | Staircase |
| H | Enemy - Human |
| E | Enemy - Elf |
| W | Enemy - Dwarf |
| L | Enemy - Halfling |
| O | Enemy - Orc |
| D | Enemy - Dragon |

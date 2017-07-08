//
// Created by mbshqqb on 16-11-30.
//


#include	<stdio.h>
#include	<fcntl.h>
#include <cstdlib>
#include <unistd.h>
#include <cstring>

void test( )
{
    char buf[BUFSIZ];
    char*filename;
    scanf("%s",filename);
    /* open devices */
    int fdout = open( filename, O_WRONLY );
    if ( fdout == -1 ){
        perror(filename);
        exit(1);
    }
    int flag;
    flag=fcntl(fdout,F_GETFL);
    flag|=O_SYNC;
    fcntl(fdout,F_SETFL,flag);

    /* loop until EOF on input */
    while( fgets(buf, BUFSIZ, stdin) != NULL )
        if ( write(fdout, buf, strlen(buf)) == -1 )
            break;
    close( fdout );

}
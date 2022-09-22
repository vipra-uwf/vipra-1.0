      PROGRAM SPLITXMOL

      CHARACTER (LEN=20) FILENAME(1000), FILENANE(1000)
      CHARACTER (LEN=10) MESSAGE
      CHARACTER (LEN=2) atom
      CHARACTER(LEN=500) rest
      DOUBLE PRECISION R0(1000,3)
      DIMENSION itr(1000),KTYPE(1000)

      open (unit=2, file ='b757-182.xyz')
      open (unit=7, file ='coord.d')

      read(2,*) NP
      read(2,*)
      do i=1,NP
         read(2,*)atom, R0(i,1), R0(i,2), R0(i,3)
         if(atom.eq.'C ')then
            itr(i)=1
            ktype(i)=13
         else
            ktype(i)=16
            itr(i)=2
         endif   
      enddo

      CUBE=1e10

      WRITE(7,*)"B757-182"  
      WRITE(7,100) NP
      WRITE(7,300) 0.,0.005
      WRITE(7,300) CUBE, CUBE, CUBE
C                                                                                                                      
      DO 11 I=1,NP
           WRITE(7,350) I,KTYPE(I),(R0(I,N),N=1,3),itr(i)
 11            CONTINUE
C                                                                                                                      
      DO 12 I=1,NP
           WRITE(7,360 )I,0, 0, 0
 12            CONTINUE
C                                                                                                                      
      DO 13 I=1,NP
           WRITE(7,360)I,0, 0, 0
 13            CONTINUE
C                                                                                                                      
      DO 14 I=1,NP
           WRITE(7,360)I,0, 0, 0
 14            CONTINUE
C                                                                                                                      
      DO 15 I=1,NP
           WRITE(7,360)I,0, 0, 0
 15            CONTINUE

               close(7)
 100        FORMAT(4I6)
 200        FORMAT(4F12.6)
 300        FORMAT(3E20.11)
 350        FORMAT(2I5,3E20.11,I3)
 360       FORMAT(I5,3E20.11)





      close(2)


      
      stop
      end

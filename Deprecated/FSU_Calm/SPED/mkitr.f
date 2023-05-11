cccc   Make a very large diamond from the diamond.d file in Bren' code
cccc
         dimension R0(70000,6),R1(70000,3),R2(70000,3),R3(70000,3),
     *  R4(70000,3),cube(3),KT(10000),KTYPE(70000),HEAD(20),noa(100)
     *   ,itr(70000),perub(3),perlb(3),bndvel(3),k1(70000)


        open(unit=11,file='coord.d')
      READ(11,1800) HEAD
      READ(11,*) NP
      READ(11,*) TTIME,DELTA
      READ(11,*) (CUBE(N),N=1,3)
 1800  FORMAT(20A2)


      nma = 0
      nta = 0

      DO I=1,NP
           READ(11,*) K,KTYPE(i),(R0(K,N),N=1,3),itr(k)
c           do n=1,3
c              R0(K,N)=R0(K,N)+CUBE(N)/2
c                if(R0(K,N).gt.cube(n)/2.0d0) R0(K,N)=R0(K,N)-cube(n)
c           enddo


c           KTYPE(K)=KT(NATOM)

c           if(ktype(k).eq.0) then
c                write(6,*) 'unknown atom type for atom ',k
c                include 'close.inc'
c                stop
c           endif
           noa(ktype(k)) = noa(ktype(k)) + 1

      ENDDO
C
      DO I=1,NP
           READ(11,*) K,(R1(K,N),N=1,3)
           DO N=1,3
                R1(k,N)=R1(k,N)*DELTA
                R1(k,N)=0
          ENDDO
      ENDDO
C
      DO I=1,NP
           READ(11,*) K,(R2(K,N),N=1,3)
      ENDDO
C
      DO I=1,NP
           READ(11,*) K,(R3(K,N),N=1,3)
      ENDDO
C
      DO I=1,NP
c           READ(11,*) K,(R4(K,N),N=1,3)
      ENDDO
        write(*,*) (cube(i),i=1,3)

        close(11)

        k=0
        do i=1,NP
          itr(i)=1
           if (R0(i,3).lt.20)then
          itr(i)=2
          endif
          if (R0(i,3).gt.38)then
          itr(i)=2
          endif

          if ((R0(i,3).lt.20).and.(R0(i,3).gt.12))then
          write(2,*)i
         k=k+1
          endif

       enddo   

        write(*,*)k

    
        open (unit=7, file='coord1.d')

      WRITE(7,*)"Diamond -DLC Crystal "  
      WRITE(7,100) NP,IDUM,NRA,NLA
      WRITE(7,300) TTIME,DELTA
      WRITE(7,300) (CUBE(N),N=1,3)
C                                                                                                                      
      DO 11 I=1,NP
           WRITE(7,350) I,KTYPE(I),(R0(I,N),N=1,3),itr(i)
 11            CONTINUE
C                                                                                                                      
      DO 12 I=1,NP
           WRITE(7,360) I,((R1(I,N)/DELTA),N=1,3)
 12            CONTINUE
C                                                                                                                      
      DO 13 I=1,NP
           WRITE(7,360) I,((R2(I,N)),N=1,3)
 13            CONTINUE
C                                                                                                                      
      DO 14 I=1,NP
           WRITE(7,360) I,((R3(I,N)),N=1,3)
 14            CONTINUE
C                                                                                                                      
      DO 15 I=1,NP
           WRITE(7,360) I,((R4(I,N)),N=1,3)
 15            CONTINUE

               close(7)
 100        FORMAT(4I6)
 200        FORMAT(4F12.6)
 300        FORMAT(3E20.11)
 350        FORMAT(2I5,3E20.11,I3)
 360       FORMAT(I5,3E20.11)



        end

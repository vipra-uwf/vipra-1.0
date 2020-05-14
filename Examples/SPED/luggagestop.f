cccc   Make a very large diamond from the diamond.d file in Bren' code
cccc
         dimension R0(70000,6),R1(70000,3),R2(70000,3),R3(70000,3),
     *  R4(70000,3),cube(3),KT(10000),KTYPE(70000),HEAD(20),noa(100)
     *   ,itr(70000),perub(3),perlb(3),bndvel(3),ir(70000)


        open(unit=11,file='coord.d')
      READ(11,1800) HEAD
      READ(11,*) NP
      READ(11,*) TTIME,DELTA
      READ(11,*) (CUBE(N),N=1,3)
 1800  FORMAT(20A2)

       s1=16.5
       s2=16.5
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

        open (unit=7, file='luggage.d')


        do i=1,NP
           if(ktype(i).eq.13)then
             do j=1,NP
           if(ktype(j).eq.16)then               
              rij= R0(j,1)-R0(i,1)
              if((rij.gt.0).and.(rij.lt.35)) then
        if ((abs(R0(j,2)).eq.s1).or.(abs(R0(j,2)).eq.s2))then
               ir(i)=j
              endif
              endif
             endif
             enddo
           write(7,'(2i5)') i, ir(i)
           endif
             enddo



        end

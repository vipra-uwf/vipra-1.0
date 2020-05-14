      subroutine read_data
      IMPLICIT REAL*8(A-H,O-Z)
      integer rank, size
      COMMON/mpi/ rank, size
      include 'common_files.inc'
      REAL*8 SCB, sigt1, epst1, SCA, tlug
C      COMMON/PARAMETERS/ SCB, sigt1, epst1, SCA, tlug
      integer irank, isize, ierr
      REAL temp1, temp2

c        call MPI_COMM_SIZE(MPI_COMM_WORLD, isize, ierr)
c        call MPI_COMM_RANK(MPI_COMM_WORLD, irank, ierr)      
       irank=rank
       isize=size
C
C READ INPUT DATA
C
      READ(13,*) KVC,MAXKB,KFLAG,nxmol,iluggage,dluggage
C      , tlug,SCA
C      READ(13,*) P1min,P1max,p1inc
C      READ(13,*) P2min,P2max,p2inc
C      READ(13,*) P3min,P3max,p3inc
C      READ(13,*) P4min,P4max,p4inc
C      READ(13,*) P5min,P5max,p5inc
      READ(13,*) PSEED,RLL,TEM
      READ(13,*) IPOT
      ktmax=6
      ilj=0

1     continue       

      READ(13,*,end=2) natom, xma, epst , sigt, epss
      if(natom.le.0) go to 1
      ilj = 1
      if(kt(natom).eq.0) then
           ktmax = ktmax + 1
           if(ktmax.gt.ntypes) then
                write(*,*) 'Maximum ntypes of ',ntypes,' exceeded'
                write(*,*) 'Change NTYPES in common_n.inc and recompile'
                include 'close.inc'
                stop
           endif
           kt(natom) = ktmax
           kt2(ktmax) = natom
      endif
      xmass(kt(natom)) = xma
      sig(kt(natom),kt(natom)) = sigt
      eps(kt(natom),kt(natom)) = epst
      go to 1

2     continue
      


C      npar1= int((P1max-P1min)/p1inc)+1
C      npar2=int((P2max-P2min)/p2inc)+1
C      npar3=int((P3max-P3min)/p3inc)+1 
C      npar4=int((P4max-P4min)/p4inc)+1 
C      npar5=int((P5max-P5min)/p5inc)+1 
C      nsize=npar1*npar2*npar3*npar4*npar5

c      if (irank.eq.0)then

c      if (nsize.gt.isize)then
c         WRITE(9,*) 'no of processors lower',nsize,isize
c         WRITE(9,*) 'First parameter increment doubled'
c         i1inc=i1inc*2
c       endif
c       npar1= int((P1max-P1min)/p1inc)+1
c      nsize=npar1*npar2*npar3

c      if (nsize.gt.isize)then
c         WRITE(9,*) 'no of processors still lower after' 
c         WRITE(9,*) 'First parameter increment doubled'
c         WRITE(9,*) 'Check params or inrease procs'
c       call MPI_ABORT(MPI_COMM_WORLD, ierr)
c       stop
c       endif

c       endif

c      call MPI_BCAST(i1inc,1,MPI_INTEGER,0,MPI_COMM_WORLD,ierr) 
c      call MPI_BCAST(npar1,1,MPI_INTEGER,0,MPI_COMM_WORLD,ierr)
c      call MPI_BCAST(npar2,1,MPI_INTEGER,0,MPI_COMM_WORLD,ierr)
c      call MPI_BCAST(npar3,1,MPI_INTEGER,0,MPI_COMM_WORLD,ierr)
c      call MPI_BCAST(npar4,1,MPI_INTEGER,0,MPI_COMM_WORLD,ierr)
c      call MPI_BCAST(npar5,1,MPI_INTEGER,0,MPI_COMM_WORLD,ierr)
c      call MPI_BCAST(nsize,1,MPI_INTEGER,0,MPI_COMM_WORLD,ierr)
c      CALL MPI_BARRIER(MPI_COMM_WORLD, ierr)
 
C       write(9,*)'prob size',npar1,npar2,npar3,npar4,npar5,nsize

 
C      i1=0
C      do i=1,npar1
C         do j=1,npar2
C            do k=1,npar3
C            do k1=1,npar4
C            do k2=1,npar5
C            i1=i1+1
C            if (irank.eq.(i1-1))then
C         SCB=P1min+p1inc*(i-1)     
C         sigt1=P2min+P2inc*(j-1)
C         epst1=(p3min+P3inc*(k-1))*100000        
C         SCA=P4min+p4inc*(k1-1)     
C         tlug=P5min+p5inc*(k2-1)     
C           endif
C           enddo
C           enddo
C           enddo
C           enddo
C           enddo

        write(9,*)'parameters SCB sigt1 epst1,SCA,tlug ', 
     &   SCB,sigt1,epst1,SCA, tlug

       do i=3,6
          do j=3,6
          eps(i,j)=epst1
          sig(i,j)=sigt1
          enddo
       enddo   

       do i=6,6
          do j=6,6
          eps(i,j)=epst1
          enddo
       enddo   

      


C
C RESTART INFORMATION FROM PREVIOUS RUN
C

      READ(11,1800) HEAD
      READ(11,*) NP
      READ(11,*) TTIME,DELTA
      READ(11,*) (CUBE(N),N=1,3)

      if(np.gt.npmax) then
           write(*,*) 'np= ',np,' greater than npmax= ',npmax
           write(*,*) 'increase npmax and recompile'
           include 'close.inc'
           stop
      endif

      nma = 0
      nta = 0

      DO I=1,NP
           READ(11,*) K,NATOM,(R0(K,N),N=1,3),itr(k)
           do n=1,3
                if(R0(K,N).gt.cube(n)/2.0d0) R0(K,N)=R0(K,N)-cube(n)
           enddo
           KTYPE(K)=KT(NATOM)

           if(ktype(k).eq.0) then
                write(6,*) 'unknown atom type for atom ',k
                include 'close.inc'
                stop
           endif
           noa(ktype(k)) = noa(ktype(k)) + 1

C
c set up list of nonrigid and thermostated atoms
           if(itr(k).ne.2) then
                nma = nma + 1
                mlist(nma) = k
                if(itr(k).eq.1) then
                     nta = nta + 1
                     nlist(nta) = k
                endif
           endif
c
      ENDDO
C
      DO I=1,NP
           READ(11,*) K,(R1(K,N),N=1,3)
           DO N=1,3
                R1(k,N)=R1(k,N)*DELTA
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
           READ(11,*) K,(R4(K,N),N=1,3)
      ENDDO
C
C ESTABLISH INITIAL POSITIONS FOR NEIGHBOR LIST UPDATE
C
      DO 8 I=1,3
           DO 7 J=1,NP
                R0L(J,I)=R0(J,I)
7          CONTINUE
8     CONTINUE
C
      VOL=CUBE(1)*CUBE(2)*CUBE(3)
C
      DO 6 I=1,3
           CUBE2(I)=CUBE(I)/2.0D0
6     CONTINUE
C
      DELTSQ=DELTA*DELTA/2.0D0
      TTCONV=2.0d0/3.0d0/FLOAT(NP)
cccccccccccc
c convert luggage stop time to steps
      itlug=tlug/delta
cread luggage positions
      if (iluggage.eq.1)then
         do i=1,NP
            if (itr(i).eq.1)then
        read(19,'(2i5)') k, ilug(k)
            endif
         enddo
       else  
         do i=1,NP
            ilug(i)=0
         enddo
       endif  

      return
  100 FORMAT(4I6)
  200 FORMAT(4F12.6)
  300 FORMAT(3E20.11)
  350 FORMAT(2I5,3E20.11,I3)
  360 FORMAT(I5,3E20.11)
 1800 FORMAT(20A2)

      end 

      subroutine write_data1
      IMPLICIT REAL*8(A-H,O-Z)
      include 'common_files.inc'
c      WRITE(9,500) HEAD
c      WRITE(9,600) KVC*MAXKB,MAXKB
c      WRITE(9,700) 1,1,1,ECONV
c      WRITE(9,900) TEM,PSEED
c      call flush(9)
      return
  500 FORMAT('*CLASSICAL DYNAMICS SIMULATION OF ',20A2)
  600 FORMAT(/,'TOTAL STEPS= ',I6,' DATA WRITTEN EVERY ',I4,
C    &' STEPS WITH ',F7.4,' fs/STEP')
     &' STEPS')
  700 FORMAT(/,'UNITS OF LENGTH, MASS, TIME AND ENERGY:',I2,' A ',I2,
     &' AMU ',I2,' fs ',F8.4,' eV')
  800 FORMAT(/,'NEIGHBOR LIST PARAMETERS: ',F12.3,' A ')
  900 FORMAT(/,'LANGEVIN PARAMETERS: ',F12.3,' k PSEED= ',F9.6,/)
      end 

      subroutine write_data2
      IMPLICIT REAL*8(A-H,O-Z)
      integer rank, size
      COMMON/mpi/ rank, size
      integer countp
      include 'common_files.inc'

        integer jrank, jsize, jerr
c        call MPI_COMM_SIZE(MPI_COMM_WORLD, jsize, jerr)
c        call MPI_COMM_RANK(MPI_COMM_WORLD, jrank, jerr)      
       jrank=rank
        jsize=size

C      count the number of passengers still in the plane

       ik1=0
       DO I=1,NP
       if(itr(i).eq.1)then
        
       
       if(abs(R0(i,2)).lt.IYMAX)then       
        ik1=ik1+1  
       endif
       endif
       enddo


       
C      write(9,112)jrank,SCB,SQRT(sig(3,3)),eps(3,3),
C     & SCA,tlug,TIME
C      endif

C 112  format('most out',i5,6f16.5)
C       If(ik1.lt.1)then 
C commented the 7 lines above - Sudheer if 2 or 1 passengers 
C stuck in the plane, just exit
       If(ik1.lt.3)then 
      write(9,111)jrank,SCB,SQRT(sig(3,3)),eps(3,3),
     & SCA,tlug,TIME
 111    format('everybody out',i5,6f16.5)
c       call MPI_FINALIZE(jerr)
c          stop
        EVERYBODY_OUT=1
          return
       endif   
c 

C      count the number of passengers exited the plane
       If(MOD(LSTEP, 10000).eq.0) then
       ik2_prev=ik2_curr
       ik2_curr=0
       DO I=1,NP
       if(itr(i).eq.1)then
       if(abs(R0(i,2)).ge.IYMAX)then
        ik2_curr=ik2_curr+1
       endif
       endif
       enddo
C      Is the simulation progressing:
C      Is the passengers exited in curr vs. prev CHECKs differ?
       If(((ik2_curr-ik2_prev).eq.0).and.(ik1.GT.2)) then
      write(9,112)jrank,SCB,SQRT(sig(3,3)),eps(3,3),
     & SCA,tlug,TIME
 112    format('non-progressive',i5,6f16.5)
        NON_PROG=1
        return
       endif
       endif


C      call flush(9)

      return
      end 

      subroutine write_data3  
      IMPLICIT REAL*8(A-H,O-Z)
      include 'common_files.inc'
      REWIND 11
      WRITE(11,1800) HEAD
      WRITE(11,100) NP,IDUM,NRA,NLA
      WRITE(11,300) TTIME,DELTA
      WRITE(11,300) (CUBE(N),N=1,3)
C
      DO 11 I=1,NP
           WRITE(11,350) I,KT2(KTYPE(I)),(R0(I,N),N=1,3),itr(i)
11    CONTINUE
C
      DO 12 I=1,NP
           WRITE(11,360) I,((R1(I,N)/DELTA),N=1,3)
12    CONTINUE
C
      DO 13 I=1,NP
           WRITE(11,360) I,((R2(I,N)),N=1,3)
13    CONTINUE
C
      DO 14 I=1,NP
           WRITE(11,360) I,((R3(I,N)),N=1,3)
14    CONTINUE
C
      DO 15 I=1,NP
           WRITE(11,360) I,((R4(I,N)),N=1,3)
15    CONTINUE

      return 

  100 FORMAT(4I6)
  200 FORMAT(4F12.6)
  300 FORMAT(3E20.11)
  350 FORMAT(2I5,3E20.11,I3)
  360 FORMAT(I5,3E20.11)
  500 FORMAT('*CLASSICAL DYNAMICS SIMULATION OF ',20A2)
  600 FORMAT(/,'TOTAL STEPS= ',I6,' DATA WRITTEN EVERY ',I4,
C    &' STEPS WITH ',F7.4,' fs/STEP')
     &' STEPS')
  700 FORMAT(/,'UNITS OF LENGTH, MASS, TIME AND ENERGY:',I2,' A ',I2,
     &' AMU ',I2,' fs ',F8.4,' eV')
  800 FORMAT(/,'NEIGHBOR LIST PARAMETERS: ',F12.3,' A ')
  900 FORMAT(/,'LANGEVIN PARAMETERS: ',F12.3,' k PSEED= ',F9.6,/)
 1200 FORMAT('NEIGHBOR LIST UPDATES: ',/)
 1300 FORMAT(10I4,/)
 1400 FORMAT(8X,'ENERGY(eV)',5X,'T',6X,'TSTEP(fs)  TIME(fs)',/)
 1500 FORMAT(I6,F14.8,F10.3,2F9.3)
 1800 FORMAT(20A2)
      end 


      SUBROUTINE MODEL
      IMPLICIT REAL*8(A-H,O-Z)
c
      include 'common_files.inc'
c
c set forces to zero
C	
      DO J=1,3
           DO I=1,NP
                rnp(i,j) = 0.0d0
           ENDDO
      ENDDO





C set potential energy to zero
      tote = 0.0d0
       sss = noa(1)+noa(2)+noa(3)+noa(4)
c       if((ipot.eq.1).and.(sss.ne.0)) CALL CAGUTS
c       if((ipot.eq.2).and.((noa(1)+noa(2)+noa(3)).ne.0)) call tight_bind
       if(ILJ.eq.1) then 
c          call cpu_time(time0)
          call ljguts
c          call cpu_time(time1)
c          time3 = time3 + time1-time0
       endif   
c      call ljcont

c Luggage stop
       IF(iluggage.eq.1)then
       do i=1,NP
          if (itr(i).eq.1)then
       if (abs(R0(i,1)-R0(ilug(i),1)).le.dluggage)then
       La(i)=La(i)+1
       IF (La(i).eq.1)then
         La1(i)=LSTEP
         La2(i)=LSTEP+itlug
         do j=1,3
         QR0(i,j)= R0(i,j)
         enddo

       endif
      endif
      
         endif
c         write(37,*) 'luggage for ',LSTEP,i,La1(i),La2(i), QR0(i,1)
      enddo
      endif

cccccccccccccccccccccccccccccccccccccc
      if (kflag.eq.6)then
      RSQCRT=(0.5d0*RLL)**2
      DO 4 I=1,NP
      RSQ=0.0D0
      DO 3 J=1,3
           R=R0(I,J)-R0L(I,J)
           R = R - CUBE(J)*ANINT(R/CUBE(J))
           RSQ=RSQ+R*R
C
3     CONTINUE
           IF(RSQ.GT.RSQCRT) GO TO 5
4     CONTINUE
      LCHK=2
      GO TO 8
C

5     CONTINUE
	
C
C UPDATE NEIGHBOR LIST
C
      DO 7 J=1,3
           DO 6 I=1,NP
                R0L(I,J)=R0(I,J)
6          CONTINUE
7     CONTINUE
C
      KCHK=KCHK+1
C      NCHK(KCHK)=KB
      LCHK=1
C
8     CONTINUE

	endif
ccccccccccccccccccccccccccccccccccccccccc


      return
      end

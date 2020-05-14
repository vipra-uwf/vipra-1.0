      SUBROUTINE LJGUTS
      IMPLICIT REAL*8(A-H,O-Z)
      include 'common_files.inc'
C
c Find the LJ neighbor list
c

c         write(*,*) 'rs3',RSLJ(3,3),xmms(3,3),xmm(3,3)
c         write(*,*) 'rs36',RSLJ(3,6),xmms(3,6),xmm(3,6)
c         write(*,*) 'rs66',RSLJ(6,6),xmms(6,6),xmm(6,6)
      call cpu_time(time0)
c      REAL*8 kli, i, j, RSQS, L, RR, ki, kj, kli, RRS(3), vdw, dvdw, l, dr, rnp, l1, a2, tote, r, rt,
      IF(LCHK.EQ.1) THEN

      kli=0
      do i=1,np-1
          do 311 j=i+1,np
               ki = ktype(i)
               kj = ktype(j)
               if(RSLJ(ki,kj).eq.0.0d0) go to 311
               RSQS=0.0D0
c
               DO L=1,3
                    RR=R0(I,L)-R0(J,L)
                    RR = RR - CUBE(L)*ANINT(RR/CUBE(L))
                    RSQS=RSQS+rr*rr
                    if(rsqs.gt.RSLJ(ki,kj)) go to 311
               enddo
               IF(RSQS.lt.xmms(ki,kj)) GO TO 311
               kli=kli+1
               iv(kli)=i
               jv(kli)=j
 311       continue
      enddo

      kliend=kli
      if(kliend.gt.nmabig) then
               write(*,*) 'LJ neighbor array= ',kliend
               write(*,*) 'increase nmabig and recompile'
               stop 
      endif
      endif
c     
      call cpu_time(time1)
      time2 = time2 + time1 - time0

300   format(2i10,3f15.5)
      pvdw=0.D0
      do 323 llj=1,kliend
           i=iv(llj)
           j=jv(llj)
           ki=ktype(i)
           kj=ktype(j)
c
           RSQS=0.0D0

           DO L=1,3
               RRS(L)=R0(I,L)-R0(J,L)
               RRS(L) = RRS(L) - CUBE(L)*ANINT(RRS(L)/CUBE(L))
               RSQS=RSQS+RRS(L)*RRS(L)
               IF(RSQS.GT.RMAXLJ(ki,kj)) go to 323
           ENDDO
C
           if(RSQS.LT.XMM(KI,kj)) go to 323
c table look up with linear interpolation
                 r = sqrt(rsqs) - xm(ki,kj)
                 rt = r/dellj
                 ii = int(rt)+1
                 vdw  = vlook(ii,ki,kj) +
     &                  (vlook(ii+1,ki,kj)-vlook(ii,ki,kj))*(rt-ii+1)
                 dvdw = dlook(ii,ki,kj) +
     &                  (dlook(ii+1,ki,kj)-dlook(ii,ki,kj))*(rt-ii+1)

c                if (i.eq.1)then
c                   write(60,'(3i5,3f16.5)') i,j,ii,r,vdw,dvdw
c                   write(61,'(3i5,3f16.5)') ki,kj,ii,r, vlook(ii,ki,kj), 
c     &                              dlook(ii,ki,kj)
c                endif


c$            endif
c
            pvdw=pvdw+vdw
c
            do l=1,3
                 dr = dvdw*rrs(l)
                 rnp(i,l)=rnp(i,l) + dr
                 rnp(j,l)=rnp(j,l) - dr
c                if (i.eq.1)then
c                   write(59,'(3i5,3f16.5)') i,j,l,dr, rnp(i,l), rnp(j,l)
c                endif
   
             do l1=1,3
                a2=R0(i,l1)-R0(j,l1)
            a2=a2-CUBE(l1)*ANINT(a2/CUBE(l1))
             enddo   
            enddo
 323  continue

      tote = tote + pvdw
      call cpu_time(time3)
      time4 = time4 + time3 - time1
      time5 = time5 + time3 - time0

      return
      end


      SUBROUTINE LJPARAM
      IMPLICIT REAL*8(A-H,O-Z)
      include 'common_files.inc'

c Evaluate the LJ constants: units are in Ang. and eV

c convert K to eV
      do i=1,ktmax
           eps(i,i)=4.0d0*eps(i,i)/11605.0d0
      enddo
c
      do i=1,ktmax
           do j=1,ktmax
                eps(i,j) = sqrt(eps(i,i)*eps(j,j))
                sig(i,j) = (sig(i,i)+sig(j,j))/2.0d0
                XMM(i,j)=0.0d0
                RSPL(i,j)=0.0d0
           enddo
      enddo

c
      do i=1,ktmax
           do j=1,ktmax
c
                if(eps(i,j).ne.0.0d0) then
                     XMMS(i,j) = XMM(i,j) - RLL
                     XM(i,j) = XMM(i,j)
                     RMAXLJ(i,j) = 2.20d0*sig(i,j)
                     RSLJ(i,j) = RMAXLJ(i,j)+RLL
c
                     RMAXLJ(i,j) = RMAXLJ(i,j)*RMAXLJ(i,j)
                     RSLJ(i,j) = RSLJ(i,j)*RSLJ(i,j)
                     XMM(i,j) = XMM(i,j)*XMM(i,j)
                     XMMS(i,j) = XMMS(i,j)*XMMS(i,j)
                     RSPLS(i,j) = RSPL(i,j)*RSPL(i,j)
                     sig(i,j) = sig(i,j)*sig(i,j)
                else
                     RMAXLJ(i,j) = 0.0d0
                     RSLJ(i,j) = 0.0d0
                endif
c
           enddo
      enddo
c
c
c


c generate table look up for pair interactions
C
      dellj = 0.1d0
      do i=1,ktmax
           do j=1,ktmax
                 kmax = (sqrt(rmaxlj(i,j)) - xm(i,j))/dellj
                 if(kmax+1.gt.10000) then
                 write(6,*) 'kmax,i,j: ',kmax,i,j, rmaxlj(i,j), xm(i,j)
                      include 'close.inc'
                      stop
                 endif
C
                 do k=kmax+1,10000
                      vlook(k,i,j) = 0.0d0
                      dlook(k,i,j) = 0.0d0
                 enddo
C
                 do k=kmax,1,-1
                           r = (k-1)*dellj + xm(i,j)
                           if(((i.gt.2).or.(j.gt.2)).and.(r.eq.0.0d0))
     &                           r=dellj
                           rsqs = r*r
                           if(rsqs.lt.rmaxlj(i,j)) then
c                                if((i.eq.3).and.(j.eq.3)) then
                                   
                                     r6 = (sig(i,j)/rsqs)**3
                                     vdw = eps(i,j) * r6 * (r6)
                                     dvdw = eps(i,j)/rsqs *
     &                                     r6*(12.0d0*r6)
                                    if(dvdw.gt.601437)then
                                     vdw=4140013
                                     dvdw=601437
                                    endif 

c                                if((i.eq.6).or.(j.eq.6))then
c                                   if(rsqs.gt.36)then
c                                     vdw = 0
c                                     dvdw =0
c                                   elseif(rsqs.le.36)then  
c                                     vdw=82385 
c                                     dvdw=8649
c                                   endif  
c
c                                endif
                           else
                                vdw = 0.0d0
                                dvdw = 0.0d0

                           endif
                      vlook(k,i,j) =  vdw
                      dlook(k,i,j) = dvdw
                 enddo
            enddo
      enddo

 180  format(3i10, 3f25.4)


c
      return
      end


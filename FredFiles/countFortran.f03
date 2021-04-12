program countFortran
IMPLICIT  NONE
Interface
integer(c_int) function countF(word, wordSize, text, textSize) bind (C, name="count") result(countF)
	USE ISO_C_BINDING, only: C_INT, C_CHAR
	integer(C_INT), VALUE :: wordSize	!integer :: wordSize
	integer(C_INT), VALUE :: textSize	!integer :: textSize
	character(KIND=C_CHAR) :: word(*)	!character(KIND=C_CHAR) :: word(wordSize)	!character (len = wordSize) :: word
	character(KIND=C_CHAR) :: text(*)	!character(KIND=C_CHAR) :: text(textSize)	!character (len = textSize) :: text
end function
end Interface
end program countFortran

integer(c_int) function countF(word, wordSize, text, textSize) bind (C, name="count") result(countF)
	USE ISO_C_BINDING, only: C_INT, C_CHAR
	integer(C_INT), VALUE :: wordSize	!integer :: wordSize
	integer(C_INT), VALUE :: textSize	!integer :: textSize
	character(KIND=C_CHAR) :: word(*)	!character(KIND=C_CHAR) :: word(wordSize)	!character (len = wordSize) :: word
	character(KIND=C_CHAR) :: text(*)	!character(KIND=C_CHAR) :: text(textSize)	!character (len = textSize) :: text

	integer :: j = 1
	integer :: k = 1
	!integer :: countF	! = 0

	integer :: i = 1
	countF = 0
	do while (i < textSize)	
		j = 1
		k = i		
		do while (text(k) == word(j))
			if(j==wordsize)then
				countF = countF + 1	!count++
				exit	!exit do? stop? 
			end if
			j = j + 1	!j++
			k = k + 1	!k++
		end do
		i = i + 1	!i++
	end do
	return
end function countF


!function count(word, wordSize, text, textSize) return count()
!
!!Algoritmo/Pseudocodigo, para traduzir para fortran
!	i=0
!	while(i<textsize)	
!		j=0
!		k=i		
!		while(text[k]==word[j])
!			if(j==wordsize-1)
!				count++
!				break
!			j++
!			k++
!		i++
!	return

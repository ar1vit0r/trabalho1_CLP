function count(word, wordSize, text, textSize) !bind (C, name="count")
	USE ISO_C_BINDING, only: C_INT, C_CHAR
	integer(C_INT) :: wordSize	!integer :: wordSize
	integer(C_INT) :: textSize	!integer :: textSize
	character(KIND=C_CHAR) :: word(wordSize)	!character (len = wordSize) :: word
	character(KIND=C_CHAR) :: text(textSize)	!character (len = textSize) :: text

	integer :: j = 1
	integer :: k = 1
	integer :: count	! = 0

	integer :: i = 1
	count = 0
	do while (i < textSize)	
		j = 1
		k = i		
		do while (text(k) == word(j))
			if(j==wordsize)then
				count = count + 1	!count++
				exit	!exit do? stop? 
			end if
			j = j + 1	!j++
			k = k + 1	!k++
		end do
		i = i + 1	!i++
	end do
	return
end function count

program countFortran
end program countFortran

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

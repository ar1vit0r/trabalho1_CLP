function count(word, wordSize, text, textSize) result(c)
	integer, intent(in) :: wordSize
	integer, intent(in) :: textSize
	character, intent(in) :: word(wordSize)
	character, intent(in) :: text(textSize)

	integer :: j != 1
	integer :: k != 1
	integer :: i = 1
	integer :: c
	c = 0

	do while (i < textSize)	
		j = 1
		k = i		
		do while (text(k) == word(j))	
			if(j==wordsize-1)then !if(j==wordsize)then
				c = c + 1
				exit
			end if
			j = j + 1
			k = k + 1
		end do
		i = i + 1
	end do
	return
end function count

nums = []  
n = 500
i = 0

while i < n
	num = rand(1000)
	if !nums.include?(num)
		nums.push(num)
		print num
		print " "
		i = i + 1
	end
end
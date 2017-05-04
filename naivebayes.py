
x1=[]
x2=[]
y=[]
f = open('data_naivebayes.txt','r')

i=0
first=[]
line=f.readline()
# print line
first = line.split()
x1.append(first[0])
x2.append(first[1])
y.append(first[2])

i+=1
while line:
	line=[]
	first=[]
	line=f.readline()
	#print(line)
	# print line
	first = line.split()
	if len(first)>0:
		x1.append(first[0])
		x2.append(first[1])
		y.append(first[2])
		i+=1
	# else:
		# print first

f.close()

print "Probability of y (Go, Stay), given x1 (Sunny, Rainy) and x2 (Working, Broken): "
var1=raw_input("x1: ")
var2=raw_input("x2: ")

total=len(x1)
count_1=0.0
count_2=0.0
count_3=0.0
count_4=0.0
count_5=0.0
count_6=0.0
for j in range(0,len(x1)):
	if y[j]=="go":
		count_5+=1
		if x1[j]==var1:
			count_1+=1
		if x2[j]==var2:
			count_2+=1
	if y[j]=="stay":
		count_6+=1
		if x1[j]==var1:
			count_3+=1
		if x2[j]==var2:
			count_4+=1

# p_go=(count_5/total)*(count_1/total)*(count_2/total)
# p_stay=(count_6/total)*(count_3/total)*(count_4/total)


p_go=(count_5/total)*(count_1/count_5)*(count_2/count_5)
p_stay=(count_6/total)*(count_3/count_6)*(count_4/count_6)

if p_go>p_stay:
	print "Go"
elif p_go<p_stay:
	print "Stay"
else:
	print "Equi Probability of Go and Stay"



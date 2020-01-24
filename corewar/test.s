.name		"Name"
.comment	"Comment"

live	%9999999

st r4, -500

b2:
live	%9999999

st r4, -500

live	%9999999

live	%:b2

st r4, -500
forks:
add	r2, r3, r2		;increment r2

live	%9999999


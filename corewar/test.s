.name		"Name"
.comment	"Comment"

live	%9999999
#
;
st r4, -500
#
metka1:
metka2:
b2:live	%12345

st r4, -500
live	%9999999

live	%:b2
st r4, -500
live	%9999999

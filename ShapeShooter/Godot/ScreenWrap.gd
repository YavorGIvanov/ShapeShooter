extends Node

export (Rect2) var wrapArea = null
export (bool) var horizontalWrapping = true
export (bool) var verticalWrapping = true


var AXIS = {
	HORIZONTAL = "x",
	VERTICAL = "y"
}

func _ready():
	if wrapArea == null:
		wrapArea = Rect2(Vector2(), get_viewport().size)

# Check whether the parent object is NOT in the wrap area,
# call the wrap function if it isn't
func _process(delta):
	if !wrapArea.has_point(get_parent().global_position):
		wrap()

func wrap():

	if horizontalWrapping:
		wrapBy(AXIS.HORIZONTAL)
	if verticalWrapping:
		wrapBy(AXIS.VERTICAL)

# Function to determine which side of the axis the parent has fallen off
# i.e. the left or right (x axis) or up or down (y axis)
# Return an integer for the direction the wrap is requred in
# the direction is multiplied by the gap (i.e. width or height
# ..and is added to the current axis position

func wrapBy(axis):
	# Calculate the axis adjustment required
	# I.e. get axis wrap direction and multiply by axis size
	var axisDirection = 0
	if get_parent().global_position[axis] < wrapArea.position[axis]:
		axisDirection =  1
	elif get_parent().global_position[axis] > wrapArea.size[axis]:
		axisDirection = -1
	
	# Apply the adjustment to the parent's position
	get_parent().position[axis] += axisDirection * wrapArea.size[axis]

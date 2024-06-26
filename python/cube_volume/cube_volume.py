"""
Task

Find the volume of the largest cube that will fit inside a cylinder of given height h and radius r.

Don't round your result. The result needs to be within 0.01 error margin of the expected result.

HINT: There are two cases to consider. Will it be the cylinder's height or the cylinder's radius that determines the maximum size of your cube? An if/else statement might be useful here.

Two Examples

1. for height  3, radius 7 => should return  27.0
2. for height 11, radius 5 => should return 353.55
"""



def cube_volume(h,r) -> float:
    ladoH: float = h
    ladoR: float = 2**0.5 * r
    if ladoH < ladoR:
        return ladoH
    else:
        return ladoR

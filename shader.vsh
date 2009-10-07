vs_1_1
dcl_position v0
dcl_color v1

def c111, 1.0, 1.0, 1.0, 1.0

mul r0.xyz, v0.xyz, c1.x
mov r0.w, c111.w
m4x4 oPos, r0, c2
mov oD0, v1

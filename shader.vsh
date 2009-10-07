vs_1_1
dcl_position v0
dcl_color v1

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; c0 is FINAL_RADIUS            ;;
;; c1 is t                       ;;
;; c2 - c5 is matrix             ;;
;; c111 is 1.0f                  ;;
;; c112 is 0.5f                  ;;
;;                               ;;
;; r0.x is 1/current radius      ;;
;; r1.x is a quotient            ;;
;; r2 is a vertex after morphing ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

def c111, 1.0, 1.0, 1.0, 1.0 ;constant one

dp3 r0.x, v0, v0
rsq r0.x, r0.x

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;  r1.x = 1+t*( (FINAL_RADIUS/r0) -1)  ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

mul r1.x, r0.x, c0.x
sub r1.x, r1.x, c111.x
mul r1.x, r1.x, c1.x
add r1.x, r1.x, c111.x

mul r2.xyz, v0.xyz, r1.x
mov r2.w, c111.w

m4x4 oPos, r2, c2
mov oD0, v1

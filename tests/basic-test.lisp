; Various imports from libc and others

(defun rand () i32)         ; libc: int rand(void)
(defun sinf (f32) f32)      ; libc: float sinf(float)
(defun cosf (f32) f32)      ; libc: float cosf(float)
(defun puts (&u8) i32)      ; libc: int puts(const char*)

; Actual code
(define string-constant "This is a string constant")
(define float-constant 3.14)

(define named-lambda lambda () f32
  (+ float-constant 2))

(defun get-float () f32
  float-constant)

(defun test-lambda (i128) f32
  ((lambda () f32
    ((lambda ((root_value f32)) f32
      ((lambda ((in_value f32)) f32
        (+ (/ in_value (get-float)) (* (+ 1.22 in_value) 2))) 42.5)) (named-lambda)))))

(defun test-scope () u32
  (let ((x 42))
    ((lambda () u32 (+ x (rand))))))    ; (lambda () u32 x) will crash the compiler, captures are not implemented
                                        ; but (+ x (rand)) will not, because X resolves to constant

(defun test-scope-lambda () i32
  (let ((x (lambda (f16) i32 (rand))))
    (x 0.2)))

;(defun test-boolean () boolean
;    (< 0.5 0.2))

;(defun test-if ((in_value f16)) f16
;  (if (< in_value 0.5)
;    in_value
;    (* in_value 2))

(defun test-if () i32
  (if 1
    (puts "true")
    (puts "false"))
  (puts "end"))

(defun main () i32
  (puts "Hello World")
  (test-if)
  (puts string-constant)
  (test-scope)
  (test-scope-lambda)
  (let ((x (test-lambda 15041993)))
      0))

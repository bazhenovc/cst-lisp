;;  MIT License
;;
;;  Copyright (c) 2019 Kyrylo Bazhenov
;;
;;  Permission is hereby granted, free of charge, to any person obtaining a copy
;;  of this software and associated documentation files (the "Software"), to deal
;;  in the Software without restriction, including without limitation the rights
;;  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
;;  copies of the Software, and to permit persons to whom the Software is
;;  furnished to do so, subject to the following conditions:
;;
;;  The above copyright notice and this permission notice shall be included in all
;;  copies or substantial portions of the Software.
;;
;;  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
;;  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
;;  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
;;  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
;;  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
;;  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;;  SOFTWARE.

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
    ((lambda ([root_value f32]) f32
      ((lambda ([in_value f32]) f32
        (puts "test-lambda")
        (+ (/ in_value (get-float)) (* (+ 1.22 in_value) 2))) 42.5)) (named-lambda)))))

(defun test-scope () u32
  (let ([x 42])
    ((lambda () u32 (+ x (rand))))))    ; (lambda () u32 x) will crash the compiler, captures are not implemented
                                        ; but (+ x (rand)) will not, because X resolves to constant

(defun test-scope-lambda () i32
  (let ([x (lambda (f16) i32 (rand))])
    (x 0.2)))

;(defun test-boolean () boolean
;    (< 0.5 0.2))

;(defun test-if ((in_value f16)) f16
;  (if (< in_value 0.5)
;    in_value
;    (* in_value 2))

;(defun test-if () i32
;  (if 1
;    (puts "true")
;    (puts "false")))
;
;(defun test-if-let () i32
;  (let ([x (if 1 "true" "false")])
;    (puts x)))

(defun test-cond-if () i32
  (cond
    [0 (puts "cond failed")]
    [else (puts "cond passed")]))

(defun test-cond () i32
  (cond
    [0 (puts "0 is false, this should not happen")]
    [1 (puts "1 is true")]
    [2 (puts "2 is true, but this should not happen")]
    [3 (puts "3 is also true, however this is shoudl not happen too")]
    [else (puts "else, we'll never see this one")
          (puts "if we ever see this message - something is seriously broken")]))

(defun test-func-with-args ([x f32] [y f64]) f32
  y x)

(defun main () i32
  (puts "Hello World")
  ;(test-if)
  ;(test-if-let)
  (test-cond-if)
  (test-cond)
  (puts string-constant)
  (test-scope)
  (test-scope-lambda)
  (test-func-with-args 3.14 1.12)
  (let ([x (test-lambda 15041993)])
    0))

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

(define named-lambda (lambda () f32
  (+ float-constant 2)))

(defun get-float () f32
  float-constant)

(defun test-lambda (i128) f32
  ((lambda () f32
    ((lambda ([root_value f32]) f32
      ((lambda ([in_value f32]) f32
        (puts "test-lambda")
        (+ (/ in_value (get-float))
           (* (+ 1.22 in_value) 2))) 42.5)) (named-lambda)))))

(defun test-scope () u32
  (let ([x 42])
    ((lambda () u32 (+ x (rand))))))    ; (lambda () u32 x) will crash the compiler, captures are not implemented
                                        ; but (+ x (rand)) will not, because X resolves to constant

(defun test-scope-lambda () i32
  (let ([x (lambda (f16) i32 (rand))])
    (x 0.2)))

(defun test-cond-if () void
  (cond
    [0 (puts "cond failed")]
    [else (puts "cond passed")]))

(defun test-cond () void
  (cond
    [0 (puts "0 is false, this should not happen")]
    [1 (puts "1 is true")]
    [2 (puts "2 is true, but this should not happen")]
    [3 (puts "3 is also true, however this is should not happen too")]
    [else (puts "else, we'll never see this one")
          (puts "if we ever see this message - something is seriously broken")]))

(defun test-integer-binary-operators () void
  (puts "Testing integer binary operators")
  (cond
    [(= 5 5) (puts "5 equals 5")] [else (puts "integer equality operator failed")])
  (cond
    [(~= 1 5) (puts "1 not-equals 5")] [else (puts "integer not-equality operator failed")])
  (cond
    [(> 9 3) (puts "9 is greater than 3")] [else (puts "integer greater-than operator failed")])
  (cond
    [(< 2 4) (puts "2 is lesser than 4")] [else (puts "integer lesser-than operator failed")])
  (cond
    [(>= 7 5) (puts "7 equals or greater than 5")] [else (puts "integer greater-equals operator failed")])
  (cond
    [(>= 7 7) (puts "7 equals or greater than 7")] [else (puts "integer greater-equals operator failed")])
  (cond
    [(<= 5 7) (puts "5 equals or lesser than 7")] [else (puts "integer lesser-equals operator failed")])
  (cond
    [(<= 7 7) (puts "7 equals or lesser than 7")] [else (puts "integer lesser-equals operator failed")]))

(defun test-float-binary-operators () void
  (puts "Testing floating-point binary operators")
  (cond
    [(= 5.0 5.0) (puts "5.0 equals 5.0")] [else (puts "float equality operator failed")])
  (cond
    [(~= 1.8 5.14) (puts "1.8 not-equals 5.14")] [else (puts "float not-equality operator failed")])
  (cond
    [(> 9.2 3.3) (puts "9.2 is greater than 3.3")] [else (puts "float greater-than operator failed")])
  (cond
    [(< 2.2 4.1) (puts "2.2 is lesser than 4.1")] [else (puts "float lesser-than operator failed")])
  (cond
    [(>= 7.1 5.2) (puts "7.1 equals or greater than 5.2")] [else (puts "float greater-equals operator failed")])
  (cond
    [(>= 7.0 7.0) (puts "7.0 equals or greater than 7.0")] [else (puts "float greater-equals operator failed")])
  (cond
    [(<= 5.0 7.0) (puts "5.0 equals or lesser than 7.0")] [else (puts "float lesser-equals operator failed")])
  (cond
    [(<= 7.0 7.0) (puts "7.0 equals or lesser than 7.0")] [else (puts "float lesser-equals operator failed")]))

(defun test-func-with-args ([x f32] [y f64]) f32
  y x)

(defun test-type-cast () void
  (let ([typed-constant i8 255])
    (cond [(= typed-constant -127) (puts "type cast test passed")] [else (puts "type cast test failed")])))

(defun test-loop () void
  (cond
    [(= 3 ; TODO: This is a very hard problem to solve: what should the following loop return? 3 or 4?
        (loop ([x i16 0 (< x 4) (+ x 1)]) do
          (puts "Loop iteration")
          x))
        (puts "loop test passed")]
    [else (puts "loop test failed")]))

(defstruct vector3i
    [x i32 0]
    [y i32 0]
    [z i32 0])

(defun test-struct ([vec vector3i] [vec-ptr &vector3i]) void
  0)

(defun test-struct-members () void
  (let ([vec (vector3i 1 2 3)])
    (cond
      [(= 6 (+ vec.x (+ vec.y vec.z))) (puts "struct test passed")]
      [else (puts "struct test failed")])))

(defun main () i32
  (puts "Hello World")
  (puts string-constant)
  (test-scope)
  (test-scope-lambda)
  (test-func-with-args 3.14 1.12)
  (test-cond-if)
  (test-cond)
  (test-integer-binary-operators)
  (test-float-binary-operators)
  (test-type-cast)
  (test-loop)
  (test-struct-members)
  (let ([x (test-lambda 15041993)])
    0))

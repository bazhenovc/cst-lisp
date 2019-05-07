# CST-Lisp - Compiled Static Typed Lisp

Hello, this is my experimental programming language based on LLVM libraries.

At this stage it's pretty basic, thus I recommend you to lower your expectations. Please refrain from using this code in production for now.

## Supported features

In no particular order:

* All low-level types that LLVM supports: bool, i8/u8, i16/u16, i32/u32, i64/u64, i128/u128, f16, f32, f64
* User-defined structs
* Mutable and immutable variables (immutable by default)
* Conditional branches
* Loops
* Binary arithmeric and logic operators
* Type inference
* User-defined functions and external functions from DLLs
* Lambdas and closures

## Examples

### Demo application source and output

<table>
<tr>
<td><pre lang="lisp">

    (defun main () i32
      (puts "Hello World")
      (puts string-constant)
      (test-scope)
      (test-scope-lambda)
      (test-scope-mutable)
      (test-func-with-args 3.14 1.12)
      (test-cond-if)
      (test-cond)
      (test-integer-binary-operators)
      (test-float-binary-operators)
      (test-type-cast)
      (test-loop)
      (test-struct-members)
      (test-nested-struct)
      (let ([x (test-lambda 15041993)])
        0))

</pre></td>
<td><pre>

    > cst-lisp-compiler.exe tests/basic-test.lisp -ir-binary=build/basic-test.ll -ir-plaintext=stdout
    > lli.exe basic-test.ll
    Hello World
    This is a string constant
    Mutable test passed
    Mutable test passed
    cond passed
    1 is true
    Testing integer binary operators
    5 equals 5
    1 not-equals 5
    9 is greater than 3
    2 is lesser than 4
    7 equals or greater than 5
    7 equals or greater than 7
    5 equals or lesser than 7
    7 equals or lesser than 7
    Testing floating-point binary operators
    5.0 equals 5.0
    1.8 not-equals 5.14
    9.2 is greater than 3.3
    2.2 is lesser than 4.1
    7.1 equals or greater than 5.2
    7.0 equals or greater than 7.0
    5.0 equals or lesser than 7.0
    7.0 equals or lesser than 7.0
    type cast test passed
    Loop iteration
    Loop iteration
    Loop iteration
    Loop iteration
    loop test passed
    struct test passed
    mutable struct test passed
    mutable struct test passed
    nested struct test passed
    mutable nested struct test passed
    test-lambda

</pre></td>
</tr>
</table>

### Importing external functions

Please note that comments after function declarations are added for clarity, they're not used by the compiler.

<table>
<tr>
<td><pre lang="lisp">
(defun rand () i32)         ; libc: int rand(void)
(defun sinf (f32) f32)      ; libc: float sinf(float)
(defun cosf (f32) f32)      ; libc: float cosf(float)
(defun puts (&u8) i32)      ; libc: int puts(const char*)
</pre></td>
<td><pre lang="llvm">
declare dllimport i32 @rand()
declare dllimport float @sinf(float)
declare dllimport float @cosf(float)
declare dllimport i32 @puts(i8*)
</pre></td>
</tr>
</table>

### Declaring constants and functions
<table>
<tr>
<td><pre lang="lisp">

    (define string-constant "This is a string constant")
    (define float-constant 3.14)
    
    (define named-lambda (lambda () f32
      (+ float-constant 2)))
    
    (defun get-float () f32
      float-constant)
      
    (defun test-func-with-args ([x f32] [y f64]) f32
      y x)

</pre></td>
<td><pre lang="llvm">

    define internal float @lambda() {
    __funcbody:
      ret float 0x40148F5C20000000
    }
    
    define internal float @get-float() {
    __funcbody:
      ret float 0x40091EB860000000
    }
    
    define internal float @test-func-with-args(float, double) {
    __funcbody:
      ret float %0
    }

</pre></td>
</tr>
</table>

### Declaring functions inside functions inside functions

<table>
<tr>
<td><pre lang="lisp">

    (defun test-lambda (i128) f32
      ((lambda () f32
        ((lambda ([root_value f32]) f32
          ((lambda ([in_value f32]) f32
            (puts "test-lambda")
            (+ (/ in_value (get-float))
               (* (+ 1.22 in_value) 2))) 42.5))
                 (named-lambda)))))

</pre></td>
<td><pre lang="llvm">

    define internal float @test-lambda(i128) {
    __funcbody:
      %1 = call float @lambda.1()
      ret float %1
    }
    
    define internal float @lambda.1() {
    __funcbody:
      %0 = call float @lambda()
      %1 = call float @lambda.2(float %0)
      ret float %1
    }
    
    define internal float @lambda.2(float) {
    __funcbody:
      %1 = call float @lambda.3(float 4.250000e+01)
      ret float %1
    }
    
    define internal float @lambda.3(float) {
    __funcbody:
      %1 = call i32 @puts(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @__str_literal.4, i64 0, i64 0))
      %2 = call float @get-float()
      %3 = fdiv float %0, %2
      %4 = fadd float 0x3FF3851EC0000000, %0
      %5 = fmul float %4, 2.000000e+00
      %6 = fadd float %3, %5
      ret float %6
    }

</pre></td>
</tr>
</table>

### Declaring local variables and local lambdas

<table>
<tr>
<td><pre lang="lisp">

    (defun test-scope () u32
      (let ([x 42])
        ((lambda () u32 (+ x (rand))))))
    
    (defun test-scope-lambda () i32
      (let ([x (lambda (f16) i32 (rand))])
        (x 0.2)))

</pre></td>
<td><pre lang="llvm">

    define internal i32 @test-scope() {
    __funcbody:
      %0 = call i32 @lambda.5()
      ret i32 %0
    }
    
    define internal i32 @lambda.5() {
    __funcbody:
      %0 = call i32 @rand()
      %1 = add i32 42, %0
      ret i32 %1
    }
    
    define internal i32 @test-scope-lambda() {
    __funcbody:
      %0 = call i32 @lambda.6(half 0xH3266)
      ret i32 %0
    }
    
    define internal i32 @lambda.6(half) {
    __funcbody:
      %1 = call i32 @rand()
      ret i32 %1
    }

</pre></td>
</tr>
</table>

### Using conditional branches

<table>
<tr>
<td><pre lang="lisp">

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

</pre></td>
<td><pre lang="llvm">

    define internal void @test-cond-if() {
    __funcbody:
      br i1 false, label %cond_0_body, label %cond_1_test
    
    cond_1_test:                                      ; preds = %__funcbody
      br label %cond_1_body
    
    cond_0_body:                                      ; preds = %__funcbody
      %0 = call i32 @puts(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @__str_literal.11, i64 0, i64 0))
      br label %cond_next
    
    cond_1_body:                                      ; preds = %cond_1_test
      %1 = call i32 @puts(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @__str_literal.12, i64 0, i64 0))
      br label %cond_next
    
    cond_next:                                        ; preds = %cond_1_body, %cond_0_body
      %2 = phi i32 [ %0, %cond_0_body ], [ %1, %cond_1_body ]
      ret void
    }
    
    define internal void @test-cond() {
    __funcbody:
      br i1 false, label %cond_0_body, label %cond_1_test
    
    cond_1_test:                                      ; preds = %__funcbody
      br i1 true, label %cond_1_body, label %cond_2_test
    
    cond_2_test:                                      ; preds = %cond_1_test
      br i1 true, label %cond_2_body, label %cond_3_test
    
    cond_3_test:                                      ; preds = %cond_2_test
      br i1 true, label %cond_3_body, label %cond_4_test
    
    cond_4_test:                                      ; preds = %cond_3_test
      br label %cond_4_body
    
    cond_0_body:                                      ; preds = %__funcbody
      %0 = call i32 @puts(i8* getelementptr inbounds ([35 x i8], [35 x i8]* @__str_literal.13, i64 0, i64 0))
      br label %cond_next
    
    cond_1_body:                                      ; preds = %cond_1_test
      %1 = call i32 @puts(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @__str_literal.14, i64 0, i64 0))
      br label %cond_next
    
    cond_2_body:                                      ; preds = %cond_2_test
      %2 = call i32 @puts(i8* getelementptr inbounds ([38 x i8], [38 x i8]* @__str_literal.15, i64 0, i64 0))
      br label %cond_next
    
    cond_3_body:                                      ; preds = %cond_3_test
      %3 = call i32 @puts(i8* getelementptr inbounds ([54 x i8], [54 x i8]* @__str_literal.16, i64 0, i64 0))
      br label %cond_next
    
    cond_4_body:                                      ; preds = %cond_4_test
      %4 = call i32 @puts(i8* getelementptr inbounds ([31 x i8], [31 x i8]* @__str_literal.17, i64 0, i64 0))
      %5 = call i32 @puts(i8* getelementptr inbounds ([60 x i8], [60 x i8]* @__str_literal.18, i64 0, i64 0))
      br label %cond_next
    
    cond_next:                                        ; preds = %cond_4_body, %cond_3_body, %cond_2_body, %cond_1_body, %cond_0_body
      %6 = phi i32 [ %0, %cond_0_body ], [ %1, %cond_1_body ], [ %2, %cond_2_body ], [ %3, %cond_3_body ], [ %5, %cond_4_body ]
      ret void
    }

</pre></td>
</tr>
</table>

### Declaring and using mutable variables

<table>
<tr>
<td><pre lang="lisp">

    (defun test-scope-mutable () void
      (let ([x #:mutable i32 0])
        (cond
          [(= 0 x) (puts "Mutable test passed")]
          [else (puts "Mutable test failed")])
        (set x (+ x 42))
        (cond
          [(= 42 x) (puts "Mutable test passed")]
          [else (puts "Mutable test failed")])))

</pre></td>
<td><pre lang="llvm">

    define internal void @test-scope-mutable() {
    __funcbody:
      %0 = alloca i32
      store i32 0, i32* %0
      %1 = load i32, i32* %0
      %2 = icmp eq i32 0, %1
      br i1 %2, label %cond_0_body, label %cond_1_test

    cond_1_test:                                      ; preds = %__funcbody
      br label %cond_1_body

    cond_0_body:                                      ; preds = %__funcbody
      %3 = call i32 @puts(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @__str_literal.7, i64 0, i64 0))
      br label %cond_next

    cond_1_body:                                      ; preds = %cond_1_test
      %4 = call i32 @puts(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @__str_literal.8, i64 0, i64 0))
      br label %cond_next

    cond_next:                                        ; preds = %cond_1_body, %cond_0_body
      %5 = phi i32 [ %3, %cond_0_body ], [ %4, %cond_1_body ]
      %6 = load i32, i32* %0
      %7 = add i32 %6, 42
      store i32 %7, i32* %0
      %8 = load i32, i32* %0
      %9 = icmp eq i32 42, %8
      br i1 %9, label %cond_0_body2, label %cond_1_test1

    cond_1_test1:                                     ; preds = %cond_next
      br label %cond_1_body3

    cond_0_body2:                                     ; preds = %cond_next
      %10 = call i32 @puts(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @__str_literal.9, i64 0, i64 0))
      br label %cond_next4

    cond_1_body3:                                     ; preds = %cond_1_test1
      %11 = call i32 @puts(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @__str_literal.10, i64 0, i64 0))
      br label %cond_next4

    cond_next4:                                       ; preds = %cond_1_body3, %cond_0_body2
      %12 = phi i32 [ %10, %cond_0_body2 ], [ %11, %cond_1_body3 ]
      ret void
    }

</pre></td>
</tr>
</table>

### Using explicit type casts

<table>
<tr>
<td><pre lang="lisp">

    (defun test-type-cast () void
      (let ([typed-constant i8 255])
        (cond [(= typed-constant -127) (puts "type cast test passed")]
              [else (puts "type cast test failed")])))

</pre></td>
<td><pre lang="llvm">

    define internal void @test-type-cast() {
    __funcbody:
      br i1 true, label %cond_0_body, label %cond_1_test

    cond_1_test:                                      ; preds = %__funcbody
      br label %cond_1_body

    cond_0_body:                                      ; preds = %__funcbody
      %0 = call i32 @puts(i8* getelementptr inbounds ([22 x i8], [22 x i8]* @__str_literal.53, i64 0, i64 0))  br label %cond_next

    cond_1_body:                                      ; preds = %cond_1_test
      %1 = call i32 @puts(i8* getelementptr inbounds ([22 x i8], [22 x i8]* @__str_literal.54, i64 0, i64 0))
      br label %cond_next

    cond_next:                                        ; preds = %cond_1_body, %cond_0_body
      %2 = phi i32 [ %0, %cond_0_body ], [ %1, %cond_1_body ]
      ret void
    }

</pre></td>
</tr>
</table>

### Using loops

<table>
<tr>
<td><pre lang="lisp">

    (defun test-loop () void
      (cond
        [(= 3
            (loop ([x i16 0 (< x 4) (+ x 1)]) do
              (puts "Loop iteration")
              x))
            (puts "loop test passed")]
        [else (puts "loop test failed")]))

</pre></td>
<td><pre lang="llvm">

    define internal void @test-loop() {
    __funcbody:
      %0 = alloca i16
      store i16 0, i16* %0
      br i1 true, label %loop_body, label %loop_next

    cond_1_test:                                      ; preds = %loop_next
      br label %cond_1_body

    cond_0_body:                                      ; preds = %loop_next
      %1 = call i32 @puts(i8* getelementptr inbounds ([17 x i8], [17 x i8]* @__str_literal.56, i64 0, i64 0))
      br label %cond_next

    cond_1_body:                                      ; preds = %cond_1_test
      %2 = call i32 @puts(i8* getelementptr inbounds ([17 x i8], [17 x i8]* @__str_literal.57, i64 0, i64 0))
      br label %cond_next

    cond_next:                                        ; preds = %cond_1_body, %cond_0_body
      %3 = phi i32 [ %1, %cond_0_body ], [ %2, %cond_1_body ]
      ret void

    loop_body:                                        ; preds = %loop_body, %__funcbody
      %4 = load i16, i16* %0
      %5 = call i32 @puts(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @__str_literal.55, i64 0, i64 0))
      %6 = add i16 %4, 1
      store i16 %6, i16* %0
      %7 = icmp slt i16 %6, 4
      br i1 %7, label %loop_body, label %loop_next

    loop_next:                                        ; preds = %loop_body, %__funcbody
      %8 = phi i16 [ %4, %loop_body ], [ 0, %__funcbody ]
      %9 = icmp eq i16 3, %8
      br i1 %9, label %cond_0_body, label %cond_1_test
    }

</pre></td>
</tr>
</table>

### Declaring and using structures

<table>
<tr>
<td><pre lang="lisp">

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
          [else (puts "struct test failed")])
        (set vec.x 4)
        (set vec.y 5)
        (set vec.z 6)
        (cond
          [(= 15 (+ vec.x (+ vec.y vec.z))) (puts "mutable struct test passed")]
          [else (puts "mutable struct test failed")])
        (set vec (vector3i 7 8 9))
        (cond
          [(= 24 (+ vec.x (+ vec.y vec.z))) (puts "mutable struct test passed")]
          [else (puts "mutable struct test failed")])))

    (defstruct nested-struct
      [offset vector3i]
      [scale vector3i])

    (defun test-nested-struct () void
      (let ([x (nested-struct (vector3i 1 2 3) (vector3i 4 5 6))])
        (cond
          [(= 7 (+ x.offset.x x.scale.z)) (puts "nested struct test passed")]
          [else (puts "nested struct test failed")])
        (set x.offset.x 5)
        (set x.scale.z 5)
        (cond
          [(= 10 (+ x.offset.x x.scale.z)) (puts "mutable nested struct test passed")]
          [else (puts "mutable nested struct test failed")])))

</pre></td>
<td><pre lang="llvm">

    %vector3i = type { i32, i32, i32 }
    %nested-struct = type { %vector3i, %vector3i }

    define internal %vector3i @vector3i(i32, i32, i32) {
    __funcbody:
      %3 = alloca %vector3i
      %4 = getelementptr inbounds %vector3i, %vector3i* %3, i32 0, i32 0
      store i32 %0, i32* %4
      %5 = getelementptr inbounds %vector3i, %vector3i* %3, i32 0, i32 1
      store i32 %1, i32* %5
      %6 = getelementptr inbounds %vector3i, %vector3i* %3, i32 0, i32 2
      store i32 %2, i32* %6
      %7 = load %vector3i, %vector3i* %3
      ret %vector3i %7
    }

    define internal %nested-struct @nested-struct(%vector3i, %vector3i) {
    __funcbody:
      %2 = alloca %nested-struct
      %3 = getelementptr inbounds %nested-struct, %nested-struct* %2, i32 0, i32 0
      store %vector3i %0, %vector3i* %3
      %4 = getelementptr inbounds %nested-struct, %nested-struct* %2, i32 0, i32 1
      store %vector3i %1, %vector3i* %4
      %5 = load %nested-struct, %nested-struct* %2
      ret %nested-struct %5
    }

    define internal void @test-struct(%vector3i, %vector3i*) {
    __funcbody:
      ret void
    }

    define internal void @test-struct-members() {
    __funcbody:
      %0 = call %vector3i @vector3i(i32 1, i32 2, i32 3)
      %1 = alloca %vector3i
      store %vector3i %0, %vector3i* %1
      %2 = getelementptr inbounds %vector3i, %vector3i* %1, i32 0, i32 0
      %3 = load i32, i32* %2
      %4 = getelementptr inbounds %vector3i, %vector3i* %1, i32 0, i32 1
      %5 = load i32, i32* %4
      %6 = getelementptr inbounds %vector3i, %vector3i* %1, i32 0, i32 2
      %7 = load i32, i32* %6
      %8 = add i32 %5, %7
      %9 = add i32 %3, %8
      %10 = icmp eq i32 6, %9
      br i1 %10, label %cond_0_body, label %cond_1_test

    cond_1_test:                                      ; preds = %__funcbody
      br label %cond_1_body

    cond_0_body:                                      ; preds = %__funcbody
      %11 = call i32 @puts(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @__str_literal.58, i64 0, i64 0))
      br label %cond_next

    cond_1_body:                                      ; preds = %cond_1_test
      %12 = call i32 @puts(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @__str_literal.59, i64 0, i64 0))
      br label %cond_next

    cond_next:                                        ; preds = %cond_1_body, %cond_0_body
      %13 = phi i32 [ %11, %cond_0_body ], [ %12, %cond_1_body ]
      %14 = getelementptr inbounds %vector3i, %vector3i* %1, i32 0, i32 0
      store i32 4, i32* %14
      %15 = getelementptr inbounds %vector3i, %vector3i* %1, i32 0, i32 1
      store i32 5, i32* %15
      %16 = getelementptr inbounds %vector3i, %vector3i* %1, i32 0, i32 2
      store i32 6, i32* %16
      %17 = getelementptr inbounds %vector3i, %vector3i* %1, i32 0, i32 0
      %18 = load i32, i32* %17
      %19 = getelementptr inbounds %vector3i, %vector3i* %1, i32 0, i32 1
      %20 = load i32, i32* %19
      %21 = getelementptr inbounds %vector3i, %vector3i* %1, i32 0, i32 2
      %22 = load i32, i32* %21
      %23 = add i32 %20, %22
      %24 = add i32 %18, %23
      %25 = icmp eq i32 15, %24
      br i1 %25, label %cond_0_body2, label %cond_1_test1

    cond_1_test1:                                     ; preds = %cond_next
      br label %cond_1_body3

    cond_0_body2:                                     ; preds = %cond_next
      %26 = call i32 @puts(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @__str_literal.60, i64 0, i64 0))
      br label %cond_next4

    cond_1_body3:                                     ; preds = %cond_1_test1
      %27 = call i32 @puts(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @__str_literal.61, i64 0, i64 0))
      br label %cond_next4

    cond_next4:                                       ; preds = %cond_1_body3, %cond_0_body2
      %28 = phi i32 [ %26, %cond_0_body2 ], [ %27, %cond_1_body3 ]
      %29 = call %vector3i @vector3i(i32 7, i32 8, i32 9)
      store %vector3i %29, %vector3i* %1
      %30 = getelementptr inbounds %vector3i, %vector3i* %1, i32 0, i32 0
      %31 = load i32, i32* %30
      %32 = getelementptr inbounds %vector3i, %vector3i* %1, i32 0, i32 1
      %33 = load i32, i32* %32
      %34 = getelementptr inbounds %vector3i, %vector3i* %1, i32 0, i32 2
      %35 = load i32, i32* %34
      %36 = add i32 %33, %35
      %37 = add i32 %31, %36
      %38 = icmp eq i32 24, %37
      br i1 %38, label %cond_0_body6, label %cond_1_test5

    cond_1_test5:                                     ; preds = %cond_next4
      br label %cond_1_body7

    cond_0_body6:                                     ; preds = %cond_next4
      %39 = call i32 @puts(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @__str_literal.62, i64 0, i64 0))
      br label %cond_next8

    cond_1_body7:                                     ; preds = %cond_1_test5
      %40 = call i32 @puts(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @__str_literal.63, i64 0, i64 0))
      br label %cond_next8

    cond_next8:                                       ; preds = %cond_1_body7, %cond_0_body6
      %41 = phi i32 [ %39, %cond_0_body6 ], [ %40, %cond_1_body7 ]
      ret void
    }

    define internal void @test-nested-struct() {
    __funcbody:
      %0 = call %vector3i @vector3i(i32 1, i32 2, i32 3)
      %1 = call %vector3i @vector3i(i32 4, i32 5, i32 6)
      %2 = call %nested-struct @nested-struct(%vector3i %0, %vector3i %1)
      %3 = alloca %nested-struct
      store %nested-struct %2, %nested-struct* %3
      %4 = getelementptr inbounds %nested-struct, %nested-struct* %3, i32 0, i32 0
      %5 = getelementptr inbounds %vector3i, %vector3i* %4, i32 0, i32 0
      %6 = load i32, i32* %5
      %7 = getelementptr inbounds %nested-struct, %nested-struct* %3, i32 0, i32 1
      %8 = getelementptr inbounds %vector3i, %vector3i* %7, i32 0, i32 2
      %9 = load i32, i32* %8  %10 = add i32 %6, %9
      %11 = icmp eq i32 7, %10
      br i1 %11, label %cond_0_body, label %cond_1_test

    cond_1_test:                                      ; preds = %__funcbody
      br label %cond_1_body

    cond_0_body:                                      ; preds = %__funcbody
      %12 = call i32 @puts(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @__str_literal.64, i64 0, i64 0))
      br label %cond_next

    cond_1_body:                                      ; preds = %cond_1_test
      %13 = call i32 @puts(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @__str_literal.65, i64 0, i64 0))
      br label %cond_next

    cond_next:                                        ; preds = %cond_1_body, %cond_0_body
      %14 = phi i32 [ %12, %cond_0_body ], [ %13, %cond_1_body ]
      %15 = getelementptr inbounds %nested-struct, %nested-struct* %3, i32 0, i32 0
      %16 = getelementptr inbounds %vector3i, %vector3i* %15, i32 0, i32 0
      store i32 5, i32* %16
      %17 = getelementptr inbounds %nested-struct, %nested-struct* %3, i32 0, i32 1
      %18 = getelementptr inbounds %vector3i, %vector3i* %17, i32 0, i32 2
      store i32 5, i32* %18
      %19 = getelementptr inbounds %nested-struct, %nested-struct* %3, i32 0, i32 0
      %20 = getelementptr inbounds %vector3i, %vector3i* %19, i32 0, i32 0
      %21 = load i32, i32* %20
      %22 = getelementptr inbounds %nested-struct, %nested-struct* %3, i32 0, i32 1
      %23 = getelementptr inbounds %vector3i, %vector3i* %22, i32 0, i32 2
      %24 = load i32, i32* %23
      %25 = add i32 %21, %24
      %26 = icmp eq i32 10, %25
      br i1 %26, label %cond_0_body2, label %cond_1_test1

    cond_1_test1:                                     ; preds = %cond_next
      br label %cond_1_body3

    cond_0_body2:                                     ; preds = %cond_next
      %27 = call i32 @puts(i8* getelementptr inbounds ([34 x i8], [34 x i8]* @__str_literal.66, i64 0, i64 0))
      br label %cond_next4

    cond_1_body3:                                     ; preds = %cond_1_test1
      %28 = call i32 @puts(i8* getelementptr inbounds ([34 x i8], [34 x i8]* @__str_literal.67, i64 0, i64 0))
      br label %cond_next4

    cond_next4:                                       ; preds = %cond_1_body3, %cond_0_body2
      %29 = phi i32 [ %27, %cond_0_body2 ], [ %28, %cond_1_body3 ]
      ret void
    }

</pre></td>
</tr>
</table>

; ModuleID = 'testCode'
source_filename = "testCode"

@pre = global [104060401 x i32] zeroinitializer
@name = global [10201 x i32] zeroinitializer
@credit = global [101 x i32] zeroinitializer
@score = global [101 x i32] zeroinitializer
@tried = global [101 x i32] zeroinitializer
@sum_score = global i32 0
@sum_credit_tried = global i32 0
@sum_credit_get = global i32 0
@gratuate_credit = global i32 0
@cur_pre_set = global [10201 x i32] zeroinitializer
@cur_pre = global [101 x i32] zeroinitializer
@tmp = global i32 0
@cnt = global i32 1
@scanf_format_str = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@scanf_format_str.1 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@scanf_format_str.2 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@scanf_format_str.3 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@scanf_format_str.4 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@scanf_format_str.5 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@scanf_format_str.6 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@scanf_format_str.7 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@scanf_format_str.8 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@scanf_format_str.9 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@scanf_format_str.10 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@scanf_format_str.11 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@scanf_format_str.12 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@scanf_format_str.13 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@scanf_format_str.14 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@printf_format_str = private unnamed_addr constant [10 x i8] c"GPA: 0.0\0A\00", align 1
@printf_format_str.15 = private unnamed_addr constant [11 x i8] c"GPA: %.1f\0A\00", align 1
@printf_format_str.16 = private unnamed_addr constant [21 x i8] c"Hours Attempted: %d\0A\00", align 1
@printf_format_str.17 = private unnamed_addr constant [21 x i8] c"Hours Completed: %d\0A\00", align 1
@printf_format_str.18 = private unnamed_addr constant [24 x i8] c"Credits Remaining: %d\0A\0A\00", align 1
@printf_format_str.19 = private unnamed_addr constant [31 x i8] c"Possible Courses to Take Next\0A\00", align 1
@printf_format_str.20 = private unnamed_addr constant [27 x i8] c"  None - Congratulations!\0A\00", align 1
@printf_format_str.21 = private unnamed_addr constant [3 x i8] c"  \00", align 1
@printf_format_str.22 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@printf_format_str.23 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

declare i32 @scanf(i8*, ...)

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %jkk = alloca i32, align 4
  %ikk = alloca i32, align 4
  %inn = alloca i32, align 4
  %c_scanf = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format_str, i32 0, i32 0), i32* @tmp)
  br i32 1, label %loop, label %endLoop

loop:                                             ; preds = %mergeBB70, %entry
  %0 = load i32, i32* @tmp, align 4
  %1 = icmp eq i32 %0, 10
  %2 = load i32, i32* @tmp, align 4
  %3 = icmp eq i32 %2, 13
  %4 = or i1 %1, %3
  br i1 %4, label %ifBB, label %elseBB

endLoop:                                          ; preds = %mergeBB70, %ifBB, %entry
  %5 = load i32, i32* @cnt, align 4
  %6 = sub i32 %5, 1
  store i32 %6, i32* @cnt, align 4
  %7 = load i32, i32* @sum_credit_tried, align 4
  %8 = icmp eq i32 %7, 0
  br i1 %8, label %ifBB75, label %elseBB76

ifBB:                                             ; preds = %loop
  br label %endLoop

elseBB:                                           ; preds = %loop
  br label %mergeBB

mergeBB:                                          ; preds = %elseBB
  %9 = load i32, i32* @cnt, align 4
  %10 = mul i32 %9, 101
  %11 = add i32 0, %10
  %12 = getelementptr inbounds [10201 x i32], [10201 x i32]* @name, i32 0, i32 %11
  store i32 0, i32* %12, align 4
  %13 = load i32, i32* @tmp, align 4
  %14 = icmp ne i32 %13, 124
  br i1 %14, label %loop1, label %endLoop2

loop1:                                            ; preds = %loop1, %mergeBB
  %15 = load i32, i32* @cnt, align 4
  %16 = mul i32 %15, 101
  %17 = add i32 0, %16
  %18 = getelementptr inbounds [10201 x i32], [10201 x i32]* @name, i32 0, i32 %17
  %19 = load i32, i32* %18, align 4
  %20 = add i32 %19, 1
  %21 = load i32, i32* @cnt, align 4
  %22 = mul i32 %21, 101
  %23 = add i32 0, %22
  %24 = getelementptr inbounds [10201 x i32], [10201 x i32]* @name, i32 0, i32 %23
  store i32 %20, i32* %24, align 4
  %25 = load i32, i32* @tmp, align 4
  %26 = load i32, i32* @cnt, align 4
  %27 = mul i32 %26, 101
  %28 = add i32 0, %27
  %29 = getelementptr inbounds [10201 x i32], [10201 x i32]* @name, i32 0, i32 %28
  %30 = load i32, i32* %29, align 4
  %31 = load i32, i32* @cnt, align 4
  %32 = mul i32 %31, 101
  %33 = add i32 %30, %32
  %34 = getelementptr inbounds [10201 x i32], [10201 x i32]* @name, i32 0, i32 %33
  store i32 %25, i32* %34, align 4
  %c_scanf3 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format_str.1, i32 0, i32 0), i32* @tmp)
  %35 = load i32, i32* @tmp, align 4
  %36 = icmp ne i32 %35, 124
  br i1 %36, label %loop1, label %endLoop2

endLoop2:                                         ; preds = %loop1, %mergeBB
  %37 = load i32, i32* @cnt, align 4
  %38 = getelementptr inbounds [101 x i32], [101 x i32]* @credit, i32 0, i32 %37
  %c_scanf4 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format_str.2, i32 0, i32 0), i32* %38)
  %c_scanf5 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format_str.3, i32 0, i32 0), i32* @tmp)
  %c_scanf6 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format_str.4, i32 0, i32 0), i32* @tmp)
  %39 = load i32, i32* @tmp, align 4
  %40 = icmp ne i32 %39, 124
  br i1 %40, label %loop7, label %endLoop8

loop7:                                            ; preds = %mergeBB45, %endLoop2
  store i32 0, i32* getelementptr inbounds ([10201 x i32], [10201 x i32]* @cur_pre_set, i32 0, i32 0), align 4
  %41 = load i32, i32* @tmp, align 4
  %42 = icmp ne i32 %41, 59
  %43 = load i32, i32* @tmp, align 4
  %44 = icmp ne i32 %43, 124
  %45 = and i1 %42, %44
  br i1 %45, label %loop9, label %endLoop10

endLoop8:                                         ; preds = %mergeBB45, %endLoop2
  %c_scanf47 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format_str.8, i32 0, i32 0), i32* @tmp)
  %46 = load i32, i32* @cnt, align 4
  %47 = getelementptr inbounds [101 x i32], [101 x i32]* @tried, i32 0, i32 %46
  store i32 1, i32* %47, align 4
  %48 = load i32, i32* @tmp, align 4
  %49 = icmp eq i32 %48, 65
  br i1 %49, label %ifBB48, label %elseBB49

loop9:                                            ; preds = %mergeBB23, %loop7
  store i32 0, i32* getelementptr inbounds ([101 x i32], [101 x i32]* @cur_pre, i32 0, i32 0), align 4
  %50 = load i32, i32* @tmp, align 4
  %51 = icmp ne i32 %50, 44
  %52 = load i32, i32* @tmp, align 4
  %53 = icmp ne i32 %52, 59
  %54 = and i1 %51, %53
  %55 = load i32, i32* @tmp, align 4
  %56 = icmp ne i32 %55, 124
  %57 = and i1 %54, %56
  br i1 %57, label %loop11, label %endLoop12

endLoop10:                                        ; preds = %mergeBB23, %loop7
  %58 = load i32, i32* @cnt, align 4
  %59 = mul i32 %58, 101
  %60 = mul i32 %59, 101
  %61 = mul i32 %60, 101
  %62 = add i32 0, %61
  %63 = add i32 %62, 0
  %64 = add i32 %63, 0
  %65 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %64
  %66 = load i32, i32* %65, align 4
  %67 = add i32 %66, 1
  %68 = load i32, i32* @cnt, align 4
  %69 = mul i32 %68, 101
  %70 = mul i32 %69, 101
  %71 = mul i32 %70, 101
  %72 = add i32 0, %71
  %73 = add i32 %72, 0
  %74 = add i32 %73, 0
  %75 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %74
  store i32 %67, i32* %75, align 4
  %76 = load i32, i32* getelementptr inbounds ([10201 x i32], [10201 x i32]* @cur_pre_set, i32 0, i32 0), align 4
  %77 = load i32, i32* @cnt, align 4
  %78 = mul i32 %77, 101
  %79 = mul i32 %78, 101
  %80 = mul i32 %79, 101
  %81 = add i32 0, %80
  %82 = load i32, i32* @cnt, align 4
  %83 = mul i32 %82, 101
  %84 = mul i32 %83, 101
  %85 = mul i32 %84, 101
  %86 = add i32 0, %85
  %87 = add i32 %86, 0
  %88 = add i32 %87, 0
  %89 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %88
  %90 = load i32, i32* %89, align 4
  %91 = mul i32 %90, 101
  %92 = mul i32 %91, 101
  %93 = add i32 %81, %92
  %94 = add i32 %93, 0
  %95 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %94
  store i32 %76, i32* %95, align 4
  store i32 1, i32* %ikk, align 4
  %ikk27 = load i32, i32* %ikk, align 4
  %96 = load i32, i32* getelementptr inbounds ([10201 x i32], [10201 x i32]* @cur_pre_set, i32 0, i32 0), align 4
  %97 = icmp sle i32 %ikk27, %96
  br i1 %97, label %loop25, label %endLoop26

loop11:                                           ; preds = %loop11, %loop9
  %98 = load i32, i32* getelementptr inbounds ([101 x i32], [101 x i32]* @cur_pre, i32 0, i32 0), align 4
  %99 = add i32 %98, 1
  store i32 %99, i32* getelementptr inbounds ([101 x i32], [101 x i32]* @cur_pre, i32 0, i32 0), align 4
  %100 = load i32, i32* @tmp, align 4
  %101 = load i32, i32* getelementptr inbounds ([101 x i32], [101 x i32]* @cur_pre, i32 0, i32 0), align 4
  %102 = getelementptr inbounds [101 x i32], [101 x i32]* @cur_pre, i32 0, i32 %101
  store i32 %100, i32* %102, align 4
  %c_scanf13 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format_str.5, i32 0, i32 0), i32* @tmp)
  %103 = load i32, i32* @tmp, align 4
  %104 = icmp ne i32 %103, 44
  %105 = load i32, i32* @tmp, align 4
  %106 = icmp ne i32 %105, 59
  %107 = and i1 %104, %106
  %108 = load i32, i32* @tmp, align 4
  %109 = icmp ne i32 %108, 124
  %110 = and i1 %107, %109
  br i1 %110, label %loop11, label %endLoop12

endLoop12:                                        ; preds = %loop11, %loop9
  %111 = load i32, i32* getelementptr inbounds ([10201 x i32], [10201 x i32]* @cur_pre_set, i32 0, i32 0), align 4
  %112 = add i32 %111, 1
  store i32 %112, i32* getelementptr inbounds ([10201 x i32], [10201 x i32]* @cur_pre_set, i32 0, i32 0), align 4
  %113 = load i32, i32* getelementptr inbounds ([101 x i32], [101 x i32]* @cur_pre, i32 0, i32 0), align 4
  %114 = load i32, i32* getelementptr inbounds ([10201 x i32], [10201 x i32]* @cur_pre_set, i32 0, i32 0), align 4
  %115 = mul i32 %114, 101
  %116 = add i32 0, %115
  %117 = getelementptr inbounds [10201 x i32], [10201 x i32]* @cur_pre_set, i32 0, i32 %116
  store i32 %113, i32* %117, align 4
  store i32 1, i32* %inn, align 4
  %inn16 = load i32, i32* %inn, align 4
  %118 = load i32, i32* getelementptr inbounds ([101 x i32], [101 x i32]* @cur_pre, i32 0, i32 0), align 4
  %119 = icmp sle i32 %inn16, %118
  br i1 %119, label %loop14, label %endLoop15

loop14:                                           ; preds = %loop14, %endLoop12
  %inn17 = load i32, i32* %inn, align 4
  %120 = getelementptr inbounds [101 x i32], [101 x i32]* @cur_pre, i32 0, i32 %inn17
  %121 = load i32, i32* %120, align 4
  %inn18 = load i32, i32* %inn, align 4
  %122 = load i32, i32* getelementptr inbounds ([10201 x i32], [10201 x i32]* @cur_pre_set, i32 0, i32 0), align 4
  %123 = mul i32 %122, 101
  %124 = add i32 %inn18, %123
  %125 = getelementptr inbounds [10201 x i32], [10201 x i32]* @cur_pre_set, i32 0, i32 %124
  store i32 %121, i32* %125, align 4
  %inn19 = load i32, i32* %inn, align 4
  %126 = add i32 %inn19, 1
  store i32 %126, i32* %inn, align 4
  %inn20 = load i32, i32* %inn, align 4
  %127 = load i32, i32* getelementptr inbounds ([101 x i32], [101 x i32]* @cur_pre, i32 0, i32 0), align 4
  %128 = icmp sle i32 %inn20, %127
  br i1 %128, label %loop14, label %endLoop15

endLoop15:                                        ; preds = %loop14, %endLoop12
  %129 = load i32, i32* @tmp, align 4
  %130 = icmp eq i32 %129, 44
  br i1 %130, label %ifBB21, label %elseBB22

ifBB21:                                           ; preds = %endLoop15
  %c_scanf24 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format_str.6, i32 0, i32 0), i32* @tmp)
  br label %mergeBB23

elseBB22:                                         ; preds = %endLoop15
  br label %mergeBB23

mergeBB23:                                        ; preds = %elseBB22, %ifBB21
  %131 = load i32, i32* @tmp, align 4
  %132 = icmp ne i32 %131, 59
  %133 = load i32, i32* @tmp, align 4
  %134 = icmp ne i32 %133, 124
  %135 = and i1 %132, %134
  br i1 %135, label %loop9, label %endLoop10

loop25:                                           ; preds = %endLoop31, %endLoop10
  %ikk28 = load i32, i32* %ikk, align 4
  %136 = mul i32 %ikk28, 101
  %137 = add i32 0, %136
  %138 = getelementptr inbounds [10201 x i32], [10201 x i32]* @cur_pre_set, i32 0, i32 %137
  %139 = load i32, i32* %138, align 4
  %140 = load i32, i32* @cnt, align 4
  %141 = mul i32 %140, 101
  %142 = mul i32 %141, 101
  %143 = mul i32 %142, 101
  %144 = add i32 0, %143
  %145 = load i32, i32* @cnt, align 4
  %146 = mul i32 %145, 101
  %147 = mul i32 %146, 101
  %148 = mul i32 %147, 101
  %149 = add i32 0, %148
  %150 = add i32 %149, 0
  %151 = add i32 %150, 0
  %152 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %151
  %153 = load i32, i32* %152, align 4
  %154 = mul i32 %153, 101
  %155 = mul i32 %154, 101
  %156 = add i32 %144, %155
  %ikk29 = load i32, i32* %ikk, align 4
  %157 = mul i32 %ikk29, 101
  %158 = add i32 %156, %157
  %159 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %158
  store i32 %139, i32* %159, align 4
  store i32 1, i32* %jkk, align 4
  %jkk32 = load i32, i32* %jkk, align 4
  %ikk33 = load i32, i32* %ikk, align 4
  %160 = mul i32 %ikk33, 101
  %161 = add i32 0, %160
  %162 = getelementptr inbounds [10201 x i32], [10201 x i32]* @cur_pre_set, i32 0, i32 %161
  %163 = load i32, i32* %162, align 4
  %164 = icmp sle i32 %jkk32, %163
  br i1 %164, label %loop30, label %endLoop31

endLoop26:                                        ; preds = %endLoop31, %endLoop10
  %165 = load i32, i32* @tmp, align 4
  %166 = icmp eq i32 %165, 59
  br i1 %166, label %ifBB43, label %elseBB44

loop30:                                           ; preds = %loop30, %loop25
  %jkk34 = load i32, i32* %jkk, align 4
  %ikk35 = load i32, i32* %ikk, align 4
  %167 = mul i32 %ikk35, 101
  %168 = add i32 %jkk34, %167
  %169 = getelementptr inbounds [10201 x i32], [10201 x i32]* @cur_pre_set, i32 0, i32 %168
  %170 = load i32, i32* %169, align 4
  %jkk36 = load i32, i32* %jkk, align 4
  %171 = load i32, i32* @cnt, align 4
  %172 = mul i32 %171, 101
  %173 = mul i32 %172, 101
  %174 = mul i32 %173, 101
  %175 = add i32 %jkk36, %174
  %176 = load i32, i32* @cnt, align 4
  %177 = mul i32 %176, 101
  %178 = mul i32 %177, 101
  %179 = mul i32 %178, 101
  %180 = add i32 0, %179
  %181 = add i32 %180, 0
  %182 = add i32 %181, 0
  %183 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %182
  %184 = load i32, i32* %183, align 4
  %185 = mul i32 %184, 101
  %186 = mul i32 %185, 101
  %187 = add i32 %175, %186
  %ikk37 = load i32, i32* %ikk, align 4
  %188 = mul i32 %ikk37, 101
  %189 = add i32 %187, %188
  %190 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %189
  store i32 %170, i32* %190, align 4
  %jkk38 = load i32, i32* %jkk, align 4
  %191 = add i32 %jkk38, 1
  store i32 %191, i32* %jkk, align 4
  %jkk39 = load i32, i32* %jkk, align 4
  %ikk40 = load i32, i32* %ikk, align 4
  %192 = mul i32 %ikk40, 101
  %193 = add i32 0, %192
  %194 = getelementptr inbounds [10201 x i32], [10201 x i32]* @cur_pre_set, i32 0, i32 %193
  %195 = load i32, i32* %194, align 4
  %196 = icmp sle i32 %jkk39, %195
  br i1 %196, label %loop30, label %endLoop31

endLoop31:                                        ; preds = %loop30, %loop25
  %ikk41 = load i32, i32* %ikk, align 4
  %197 = add i32 %ikk41, 1
  store i32 %197, i32* %ikk, align 4
  %ikk42 = load i32, i32* %ikk, align 4
  %198 = load i32, i32* getelementptr inbounds ([10201 x i32], [10201 x i32]* @cur_pre_set, i32 0, i32 0), align 4
  %199 = icmp sle i32 %ikk42, %198
  br i1 %199, label %loop25, label %endLoop26

ifBB43:                                           ; preds = %endLoop26
  %c_scanf46 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format_str.7, i32 0, i32 0), i32* @tmp)
  br label %mergeBB45

elseBB44:                                         ; preds = %endLoop26
  br label %mergeBB45

mergeBB45:                                        ; preds = %elseBB44, %ifBB43
  %200 = load i32, i32* @tmp, align 4
  %201 = icmp ne i32 %200, 124
  br i1 %201, label %loop7, label %endLoop8

ifBB48:                                           ; preds = %endLoop8
  %202 = load i32, i32* @cnt, align 4
  %203 = getelementptr inbounds [101 x i32], [101 x i32]* @score, i32 0, i32 %202
  store i32 4, i32* %203, align 4
  %c_scanf51 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format_str.9, i32 0, i32 0), i32* @tmp)
  br label %mergeBB50

elseBB49:                                         ; preds = %endLoop8
  %204 = load i32, i32* @tmp, align 4
  %205 = icmp eq i32 %204, 66
  br i1 %205, label %ifBB52, label %elseBB53

mergeBB50:                                        ; preds = %mergeBB54, %ifBB48
  %206 = load i32, i32* @gratuate_credit, align 4
  %207 = load i32, i32* @cnt, align 4
  %208 = getelementptr inbounds [101 x i32], [101 x i32]* @credit, i32 0, i32 %207
  %209 = load i32, i32* %208, align 4
  %210 = add i32 %206, %209
  store i32 %210, i32* @gratuate_credit, align 4
  %211 = load i32, i32* @cnt, align 4
  %212 = getelementptr inbounds [101 x i32], [101 x i32]* @tried, i32 0, i32 %211
  %213 = load i32, i32* %212, align 4
  %214 = icmp eq i32 %213, 1
  br i1 %214, label %ifBB68, label %elseBB69

ifBB52:                                           ; preds = %elseBB49
  %215 = load i32, i32* @cnt, align 4
  %216 = getelementptr inbounds [101 x i32], [101 x i32]* @score, i32 0, i32 %215
  store i32 3, i32* %216, align 4
  %c_scanf55 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format_str.10, i32 0, i32 0), i32* @tmp)
  br label %mergeBB54

elseBB53:                                         ; preds = %elseBB49
  %217 = load i32, i32* @tmp, align 4
  %218 = icmp eq i32 %217, 67
  br i1 %218, label %ifBB56, label %elseBB57

mergeBB54:                                        ; preds = %mergeBB58, %ifBB52
  br label %mergeBB50

ifBB56:                                           ; preds = %elseBB53
  %219 = load i32, i32* @cnt, align 4
  %220 = getelementptr inbounds [101 x i32], [101 x i32]* @score, i32 0, i32 %219
  store i32 2, i32* %220, align 4
  %c_scanf59 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format_str.11, i32 0, i32 0), i32* @tmp)
  br label %mergeBB58

elseBB57:                                         ; preds = %elseBB53
  %221 = load i32, i32* @tmp, align 4
  %222 = icmp eq i32 %221, 68
  br i1 %222, label %ifBB60, label %elseBB61

mergeBB58:                                        ; preds = %mergeBB62, %ifBB56
  br label %mergeBB54

ifBB60:                                           ; preds = %elseBB57
  %223 = load i32, i32* @cnt, align 4
  %224 = getelementptr inbounds [101 x i32], [101 x i32]* @score, i32 0, i32 %223
  store i32 1, i32* %224, align 4
  %c_scanf63 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format_str.12, i32 0, i32 0), i32* @tmp)
  br label %mergeBB62

elseBB61:                                         ; preds = %elseBB57
  %225 = load i32, i32* @tmp, align 4
  %226 = icmp eq i32 %225, 70
  br i1 %226, label %ifBB64, label %elseBB65

mergeBB62:                                        ; preds = %mergeBB66, %ifBB60
  br label %mergeBB58

ifBB64:                                           ; preds = %elseBB61
  %227 = load i32, i32* @cnt, align 4
  %228 = getelementptr inbounds [101 x i32], [101 x i32]* @score, i32 0, i32 %227
  store i32 0, i32* %228, align 4
  %c_scanf67 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format_str.13, i32 0, i32 0), i32* @tmp)
  br label %mergeBB66

elseBB65:                                         ; preds = %elseBB61
  %229 = load i32, i32* @cnt, align 4
  %230 = getelementptr inbounds [101 x i32], [101 x i32]* @tried, i32 0, i32 %229
  store i32 0, i32* %230, align 4
  %231 = load i32, i32* @cnt, align 4
  %232 = getelementptr inbounds [101 x i32], [101 x i32]* @score, i32 0, i32 %231
  store i32 0, i32* %232, align 4
  br label %mergeBB66

mergeBB66:                                        ; preds = %elseBB65, %ifBB64
  br label %mergeBB62

ifBB68:                                           ; preds = %mergeBB50
  %233 = load i32, i32* @sum_credit_tried, align 4
  %234 = load i32, i32* @cnt, align 4
  %235 = getelementptr inbounds [101 x i32], [101 x i32]* @credit, i32 0, i32 %234
  %236 = load i32, i32* %235, align 4
  %237 = add i32 %233, %236
  store i32 %237, i32* @sum_credit_tried, align 4
  %238 = load i32, i32* @sum_score, align 4
  %239 = load i32, i32* @cnt, align 4
  %240 = getelementptr inbounds [101 x i32], [101 x i32]* @score, i32 0, i32 %239
  %241 = load i32, i32* %240, align 4
  %242 = load i32, i32* @cnt, align 4
  %243 = getelementptr inbounds [101 x i32], [101 x i32]* @credit, i32 0, i32 %242
  %244 = load i32, i32* %243, align 4
  %245 = mul i32 %241, %244
  %246 = add i32 %238, %245
  store i32 %246, i32* @sum_score, align 4
  %247 = load i32, i32* @cnt, align 4
  %248 = getelementptr inbounds [101 x i32], [101 x i32]* @score, i32 0, i32 %247
  %249 = load i32, i32* %248, align 4
  %250 = icmp sgt i32 %249, 0
  br i1 %250, label %ifBB71, label %elseBB72

elseBB69:                                         ; preds = %mergeBB50
  br label %mergeBB70

mergeBB70:                                        ; preds = %elseBB69, %mergeBB73
  %c_scanf74 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @scanf_format_str.14, i32 0, i32 0), i32* @tmp)
  %251 = load i32, i32* @cnt, align 4
  %252 = add i32 %251, 1
  store i32 %252, i32* @cnt, align 4
  br i32 1, label %loop, label %endLoop

ifBB71:                                           ; preds = %ifBB68
  %253 = load i32, i32* @sum_credit_get, align 4
  %254 = load i32, i32* @cnt, align 4
  %255 = getelementptr inbounds [101 x i32], [101 x i32]* @credit, i32 0, i32 %254
  %256 = load i32, i32* %255, align 4
  %257 = add i32 %253, %256
  store i32 %257, i32* @sum_credit_get, align 4
  br label %mergeBB73

elseBB72:                                         ; preds = %ifBB68
  br label %mergeBB73

mergeBB73:                                        ; preds = %elseBB72, %ifBB71
  br label %mergeBB70

ifBB75:                                           ; preds = %endLoop
  %c_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @printf_format_str, i32 0, i32 0))
  br label %mergeBB77

elseBB76:                                         ; preds = %endLoop
  %output_gpa = alloca float, align 4
  %b = alloca float, align 4
  %a = alloca float, align 4
  %258 = load i32, i32* @sum_score, align 4
  %259 = sitofp i32 %258 to float
  store float %259, float* %a, align 4
  %260 = load i32, i32* @sum_credit_tried, align 4
  %261 = sitofp i32 %260 to float
  store float %261, float* %b, align 4
  %a78 = load float, float* %a, align 4
  %b79 = load float, float* %b, align 4
  %262 = fdiv float %a78, %b79
  store float %262, float* %output_gpa, align 4
  %output_gpa80 = load float, float* %output_gpa, align 4
  %263 = fpext float %output_gpa80 to double
  %c_printf81 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @printf_format_str.15, i32 0, i32 0), double %263)
  br label %mergeBB77

mergeBB77:                                        ; preds = %elseBB76, %ifBB75
  %264 = load i32, i32* @sum_credit_tried, align 4
  %c_printf82 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([21 x i8], [21 x i8]* @printf_format_str.16, i32 0, i32 0), i32 %264)
  %265 = load i32, i32* @sum_credit_get, align 4
  %c_printf83 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([21 x i8], [21 x i8]* @printf_format_str.17, i32 0, i32 0), i32 %265)
  %266 = load i32, i32* @gratuate_credit, align 4
  %267 = load i32, i32* @sum_credit_get, align 4
  %268 = sub i32 %266, %267
  %c_printf84 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([24 x i8], [24 x i8]* @printf_format_str.18, i32 0, i32 0), i32 %268)
  %c_printf85 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([31 x i8], [31 x i8]* @printf_format_str.19, i32 0, i32 0))
  %269 = load i32, i32* @gratuate_credit, align 4
  %270 = load i32, i32* @sum_credit_get, align 4
  %271 = icmp eq i32 %269, %270
  br i1 %271, label %ifBB86, label %elseBB87

ifBB86:                                           ; preds = %mergeBB77
  %c_printf89 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @printf_format_str.20, i32 0, i32 0))
  br label %mergeBB88

elseBB87:                                         ; preds = %mergeBB77
  %tag_cur = alloca i32, align 4
  %ii = alloca i32, align 4
  %cur = alloca i32, i32 101, align 4
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %tag = alloca i32, align 4
  %i = alloca i32, align 4
  store i32 1, i32* %i, align 4
  %i92 = load i32, i32* %i, align 4
  %272 = load i32, i32* @cnt, align 4
  %273 = icmp sle i32 %i92, %272
  br i1 %273, label %loop90, label %endLoop91

mergeBB88:                                        ; preds = %endLoop91, %ifBB86
  ret i32 0

loop90:                                           ; preds = %mergeBB95, %elseBB87
  %i96 = load i32, i32* %i, align 4
  %274 = getelementptr inbounds [101 x i32], [101 x i32]* @score, i32 0, i32 %i96
  %275 = load i32, i32* %274, align 4
  %276 = icmp eq i32 %275, 0
  br i1 %276, label %ifBB93, label %elseBB94

endLoop91:                                        ; preds = %mergeBB95, %elseBB87
  br label %mergeBB88

ifBB93:                                           ; preds = %loop90
  store i32 0, i32* %tag, align 4
  %i100 = load i32, i32* %i, align 4
  %277 = mul i32 %i100, 101
  %278 = mul i32 %277, 101
  %279 = mul i32 %278, 101
  %280 = add i32 0, %279
  %281 = add i32 %280, 0
  %282 = add i32 %281, 0
  %283 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %282
  %284 = load i32, i32* %283, align 4
  %285 = icmp eq i32 %284, 0
  br i1 %285, label %ifBB97, label %elseBB98

elseBB94:                                         ; preds = %loop90
  br label %mergeBB95

mergeBB95:                                        ; preds = %elseBB94, %mergeBB178
  %i192 = load i32, i32* %i, align 4
  %286 = add i32 %i192, 1
  store i32 %286, i32* %i, align 4
  %i193 = load i32, i32* %i, align 4
  %287 = load i32, i32* @cnt, align 4
  %288 = icmp sle i32 %i193, %287
  br i1 %288, label %loop90, label %endLoop91

ifBB97:                                           ; preds = %ifBB93
  store i32 1, i32* %tag, align 4
  br label %mergeBB99

elseBB98:                                         ; preds = %ifBB93
  br label %mergeBB99

mergeBB99:                                        ; preds = %elseBB98, %ifBB97
  store i32 1, i32* %j, align 4
  %j103 = load i32, i32* %j, align 4
  %i104 = load i32, i32* %i, align 4
  %289 = mul i32 %i104, 101
  %290 = mul i32 %289, 101
  %291 = mul i32 %290, 101
  %292 = add i32 0, %291
  %293 = add i32 %292, 0
  %294 = add i32 %293, 0
  %295 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %294
  %296 = load i32, i32* %295, align 4
  %297 = icmp sle i32 %j103, %296
  br i1 %297, label %loop101, label %endLoop102

loop101:                                          ; preds = %mergeBB171, %mergeBB99
  store i32 1, i32* %tag, align 4
  store i32 1, i32* %k, align 4
  %k107 = load i32, i32* %k, align 4
  %i108 = load i32, i32* %i, align 4
  %298 = mul i32 %i108, 101
  %299 = mul i32 %298, 101
  %300 = mul i32 %299, 101
  %301 = add i32 0, %300
  %j109 = load i32, i32* %j, align 4
  %302 = mul i32 %j109, 101
  %303 = mul i32 %302, 101
  %304 = add i32 %301, %303
  %305 = add i32 %304, 0
  %306 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %305
  %307 = load i32, i32* %306, align 4
  %308 = icmp sle i32 %k107, %307
  br i1 %308, label %loop105, label %endLoop106

endLoop102:                                       ; preds = %mergeBB171, %ifBB169, %mergeBB99
  %tag179 = load i32, i32* %tag, align 4
  %309 = icmp eq i32 %tag179, 1
  br i1 %309, label %ifBB176, label %elseBB177

loop105:                                          ; preds = %mergeBB163, %loop101
  %i110 = load i32, i32* %i, align 4
  %310 = mul i32 %i110, 101
  %311 = mul i32 %310, 101
  %312 = mul i32 %311, 101
  %313 = add i32 0, %312
  %j111 = load i32, i32* %j, align 4
  %314 = mul i32 %j111, 101
  %315 = mul i32 %314, 101
  %316 = add i32 %313, %315
  %k112 = load i32, i32* %k, align 4
  %317 = mul i32 %k112, 101
  %318 = add i32 %316, %317
  %319 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %318
  %320 = load i32, i32* %319, align 4
  %321 = getelementptr inbounds i32, i32* %cur, i32 0
  store i32 %320, i32* %321, align 4
  store i32 1, i32* %ii, align 4
  %ii115 = load i32, i32* %ii, align 4
  %i116 = load i32, i32* %i, align 4
  %322 = mul i32 %i116, 101
  %323 = mul i32 %322, 101
  %324 = mul i32 %323, 101
  %325 = add i32 0, %324
  %j117 = load i32, i32* %j, align 4
  %326 = mul i32 %j117, 101
  %327 = mul i32 %326, 101
  %328 = add i32 %325, %327
  %k118 = load i32, i32* %k, align 4
  %329 = mul i32 %k118, 101
  %330 = add i32 %328, %329
  %331 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %330
  %332 = load i32, i32* %331, align 4
  %333 = icmp sle i32 %ii115, %332
  br i1 %333, label %loop113, label %endLoop114

endLoop106:                                       ; preds = %mergeBB163, %loop101
  %tag172 = load i32, i32* %tag, align 4
  %334 = icmp eq i32 %tag172, 1
  br i1 %334, label %ifBB169, label %elseBB170

loop113:                                          ; preds = %loop113, %loop105
  %ii119 = load i32, i32* %ii, align 4
  %i120 = load i32, i32* %i, align 4
  %335 = mul i32 %i120, 101
  %336 = mul i32 %335, 101
  %337 = mul i32 %336, 101
  %338 = add i32 %ii119, %337
  %j121 = load i32, i32* %j, align 4
  %339 = mul i32 %j121, 101
  %340 = mul i32 %339, 101
  %341 = add i32 %338, %340
  %k122 = load i32, i32* %k, align 4
  %342 = mul i32 %k122, 101
  %343 = add i32 %341, %342
  %344 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %343
  %345 = load i32, i32* %344, align 4
  %ii123 = load i32, i32* %ii, align 4
  %346 = getelementptr inbounds i32, i32* %cur, i32 %ii123
  store i32 %345, i32* %346, align 4
  %ii124 = load i32, i32* %ii, align 4
  %347 = add i32 %ii124, 1
  store i32 %347, i32* %ii, align 4
  %ii125 = load i32, i32* %ii, align 4
  %i126 = load i32, i32* %i, align 4
  %348 = mul i32 %i126, 101
  %349 = mul i32 %348, 101
  %350 = mul i32 %349, 101
  %351 = add i32 0, %350
  %j127 = load i32, i32* %j, align 4
  %352 = mul i32 %j127, 101
  %353 = mul i32 %352, 101
  %354 = add i32 %351, %353
  %k128 = load i32, i32* %k, align 4
  %355 = mul i32 %k128, 101
  %356 = add i32 %354, %355
  %357 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %356
  %358 = load i32, i32* %357, align 4
  %359 = icmp sle i32 %ii125, %358
  br i1 %359, label %loop113, label %endLoop114

endLoop114:                                       ; preds = %loop113, %loop105
  %l = alloca i32, align 4
  %found = alloca i32, align 4
  store i32 0, i32* %found, align 4
  store i32 1, i32* %l, align 4
  %l131 = load i32, i32* %l, align 4
  %360 = load i32, i32* @cnt, align 4
  %361 = icmp sle i32 %l131, %360
  br i1 %361, label %loop129, label %endLoop130

loop129:                                          ; preds = %mergeBB153, %endLoop114
  store i32 1, i32* %tag_cur, align 4
  %l135 = load i32, i32* %l, align 4
  %362 = mul i32 %l135, 101
  %363 = add i32 0, %362
  %364 = getelementptr inbounds [10201 x i32], [10201 x i32]* @name, i32 0, i32 %363
  %365 = load i32, i32* %364, align 4
  %366 = getelementptr inbounds i32, i32* %cur, i32 0
  %cur136 = load i32, i32* %366, align 4
  %367 = icmp ne i32 %365, %cur136
  br i1 %367, label %ifBB132, label %elseBB133

endLoop130:                                       ; preds = %mergeBB153, %mergeBB157, %endLoop114
  %found164 = load i32, i32* %found, align 4
  %368 = icmp eq i32 %found164, 0
  br i1 %368, label %ifBB161, label %elseBB162

ifBB132:                                          ; preds = %loop129
  store i32 0, i32* %tag_cur, align 4
  br label %mergeBB134

elseBB133:                                        ; preds = %loop129
  store i32 1, i32* %ii, align 4
  %ii139 = load i32, i32* %ii, align 4
  %369 = getelementptr inbounds i32, i32* %cur, i32 0
  %cur140 = load i32, i32* %369, align 4
  %370 = icmp sle i32 %ii139, %cur140
  br i1 %370, label %loop137, label %endLoop138

mergeBB134:                                       ; preds = %endLoop138, %ifBB132
  %tag_cur154 = load i32, i32* %tag_cur, align 4
  br i32 %tag_cur154, label %ifBB151, label %elseBB152

loop137:                                          ; preds = %mergeBB143, %elseBB133
  %ii144 = load i32, i32* %ii, align 4
  %l145 = load i32, i32* %l, align 4
  %371 = mul i32 %l145, 101
  %372 = add i32 %ii144, %371
  %373 = getelementptr inbounds [10201 x i32], [10201 x i32]* @name, i32 0, i32 %372
  %374 = load i32, i32* %373, align 4
  %ii146 = load i32, i32* %ii, align 4
  %375 = getelementptr inbounds i32, i32* %cur, i32 %ii146
  %cur147 = load i32, i32* %375, align 4
  %376 = icmp ne i32 %374, %cur147
  br i1 %376, label %ifBB141, label %elseBB142

endLoop138:                                       ; preds = %mergeBB143, %ifBB141, %elseBB133
  br label %mergeBB134

ifBB141:                                          ; preds = %loop137
  store i32 0, i32* %tag_cur, align 4
  br label %endLoop138

elseBB142:                                        ; preds = %loop137
  br label %mergeBB143

mergeBB143:                                       ; preds = %elseBB142
  %ii148 = load i32, i32* %ii, align 4
  %377 = add i32 %ii148, 1
  store i32 %377, i32* %ii, align 4
  %ii149 = load i32, i32* %ii, align 4
  %378 = getelementptr inbounds i32, i32* %cur, i32 0
  %cur150 = load i32, i32* %378, align 4
  %379 = icmp sle i32 %ii149, %cur150
  br i1 %379, label %loop137, label %endLoop138

ifBB151:                                          ; preds = %mergeBB134
  store i32 1, i32* %found, align 4
  %l158 = load i32, i32* %l, align 4
  %380 = getelementptr inbounds [101 x i32], [101 x i32]* @score, i32 0, i32 %l158
  %381 = load i32, i32* %380, align 4
  %382 = icmp eq i32 %381, 0
  br i1 %382, label %ifBB155, label %elseBB156

elseBB152:                                        ; preds = %mergeBB134
  br label %mergeBB153

mergeBB153:                                       ; preds = %elseBB152
  %l159 = load i32, i32* %l, align 4
  %383 = add i32 %l159, 1
  store i32 %383, i32* %l, align 4
  %l160 = load i32, i32* %l, align 4
  %384 = load i32, i32* @cnt, align 4
  %385 = icmp sle i32 %l160, %384
  br i1 %385, label %loop129, label %endLoop130

ifBB155:                                          ; preds = %ifBB151
  store i32 0, i32* %tag, align 4
  br label %mergeBB157

elseBB156:                                        ; preds = %ifBB151
  br label %mergeBB157

mergeBB157:                                       ; preds = %elseBB156, %ifBB155
  br label %endLoop130

ifBB161:                                          ; preds = %endLoop130
  store i32 0, i32* %tag, align 4
  br label %mergeBB163

elseBB162:                                        ; preds = %endLoop130
  br label %mergeBB163

mergeBB163:                                       ; preds = %elseBB162, %ifBB161
  %k165 = load i32, i32* %k, align 4
  %386 = add i32 %k165, 1
  store i32 %386, i32* %k, align 4
  %k166 = load i32, i32* %k, align 4
  %i167 = load i32, i32* %i, align 4
  %387 = mul i32 %i167, 101
  %388 = mul i32 %387, 101
  %389 = mul i32 %388, 101
  %390 = add i32 0, %389
  %j168 = load i32, i32* %j, align 4
  %391 = mul i32 %j168, 101
  %392 = mul i32 %391, 101
  %393 = add i32 %390, %392
  %394 = add i32 %393, 0
  %395 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %394
  %396 = load i32, i32* %395, align 4
  %397 = icmp sle i32 %k166, %396
  br i1 %397, label %loop105, label %endLoop106

ifBB169:                                          ; preds = %endLoop106
  br label %endLoop102

elseBB170:                                        ; preds = %endLoop106
  br label %mergeBB171

mergeBB171:                                       ; preds = %elseBB170
  %j173 = load i32, i32* %j, align 4
  %398 = add i32 %j173, 1
  store i32 %398, i32* %j, align 4
  %j174 = load i32, i32* %j, align 4
  %i175 = load i32, i32* %i, align 4
  %399 = mul i32 %i175, 101
  %400 = mul i32 %399, 101
  %401 = mul i32 %400, 101
  %402 = add i32 0, %401
  %403 = add i32 %402, 0
  %404 = add i32 %403, 0
  %405 = getelementptr inbounds [104060401 x i32], [104060401 x i32]* @pre, i32 0, i32 %404
  %406 = load i32, i32* %405, align 4
  %407 = icmp sle i32 %j174, %406
  br i1 %407, label %loop101, label %endLoop102

ifBB176:                                          ; preds = %endLoop102
  %idx_tag = alloca i32, align 4
  %c_printf180 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @printf_format_str.21, i32 0, i32 0))
  store i32 1, i32* %idx_tag, align 4
  %idx_tag183 = load i32, i32* %idx_tag, align 4
  %i184 = load i32, i32* %i, align 4
  %408 = mul i32 %i184, 101
  %409 = add i32 0, %408
  %410 = getelementptr inbounds [10201 x i32], [10201 x i32]* @name, i32 0, i32 %409
  %411 = load i32, i32* %410, align 4
  %412 = icmp sle i32 %idx_tag183, %411
  br i1 %412, label %loop181, label %endLoop182

elseBB177:                                        ; preds = %endLoop102
  br label %mergeBB178

mergeBB178:                                       ; preds = %elseBB177, %endLoop182
  br label %mergeBB95

loop181:                                          ; preds = %loop181, %ifBB176
  %idx_tag185 = load i32, i32* %idx_tag, align 4
  %i186 = load i32, i32* %i, align 4
  %413 = mul i32 %i186, 101
  %414 = add i32 %idx_tag185, %413
  %415 = getelementptr inbounds [10201 x i32], [10201 x i32]* @name, i32 0, i32 %414
  %416 = load i32, i32* %415, align 4
  %c_printf187 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @printf_format_str.22, i32 0, i32 0), i32 %416)
  %idx_tag188 = load i32, i32* %idx_tag, align 4
  %417 = add i32 %idx_tag188, 1
  store i32 %417, i32* %idx_tag, align 4
  %idx_tag189 = load i32, i32* %idx_tag, align 4
  %i190 = load i32, i32* %i, align 4
  %418 = mul i32 %i190, 101
  %419 = add i32 0, %418
  %420 = getelementptr inbounds [10201 x i32], [10201 x i32]* @name, i32 0, i32 %419
  %421 = load i32, i32* %420, align 4
  %422 = icmp sle i32 %idx_tag189, %421
  br i1 %422, label %loop181, label %endLoop182

endLoop182:                                       ; preds = %loop181, %ifBB176
  %c_printf191 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @printf_format_str.23, i32 0, i32 0))
  br label %mergeBB178
}

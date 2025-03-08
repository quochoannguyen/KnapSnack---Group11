# Báo cáo Bài tập lớn - Nhóm 11

## 1. Thông tin nhóm
| STT | Họ và tên | MSSV | Vai trò |
|---|---|---|---|
| 1 | Bùi Chí Tiến | 24022837 | Nhóm trưởng |
| 2 | Đặng Thế Đạt | 24022772 | Thành viên |
| 3 | Nguyễn Quốc Hoàn | 24020135 | Thành viên |
| 4 | Nguyễn Thái An | 24022761 | Thành viên |
| 5 | Bùi Thanh Sơn | 24022828 | Thành viên |

---

## 2. Thông tin bài tập
- **Giải quyết bài toán Knapsack**
**Mô tả ngắn**: Bài toán Knapsack (cái ba lô) là bài toán tối ưu hóa tổ hợp, yêu cầu chọn một tập hợp các vật phẩm sao cho tổng giá trị đạt tối đa trong khi tổng trọng lượng không vượt quá sức chứa của ba lô.


---

## 3. Hướng giải quyết bài toán
### a. Phân tích bài toán
Bài toán Knapsack yêu cầu chọn một tập hợp con các vật phẩm từ danh sách cho trước, mỗi vật phẩm có trọng lượng (weight) và giá trị (value), sao cho:
Đầu vào: 
    Số lượng vật phẩm n.
    Trọng lượng tối đa của ba lô W.
    Danh sách trọng lượng của từng vật phẩm: w[1], w[2], ..., w[n].
    Danh sách giá trị của từng vật phẩm: v[1], v[2], ..., v[n].

Đầu ra: 
    Tổng giá trị tối đa có thể đạt được.

Ràng buộc: 
    Tổng trọng lượng của các vật phẩm được chọn không được vượt quá W.


### b. Thuật toán/Hướng tiếp cận
 Sử dụng phương pháp đệ quy để giải bài toán Knapsack 0-1 (mỗi vật phẩm chỉ được chọn hoặc không chọn).
Hướng tiếp cận: 
  Đầu tiên, ta xét từng vật phẩm trong danh sách:
    Không chọn vật phẩm hiện tại: Giá trị tối đa là kết quả của bài toán với các vật phẩm còn lại và cùng trọng lượng tối đa W.
    Chọn vật phẩm hiện tại (nếu trọng lượng cho phép): Giá trị tối đa là giá trị của vật phẩm hiện tại cộng với kết quả của bài toán với các vật phẩm còn lại và trọng lượng tối đa giảm đi w[i].

Lấy giá trị lớn nhất giữa hai lựa chọn trên.

Điều kiện dừng của đệ quy:
Nếu không còn vật phẩm nào (n = 0) hoặc trọng lượng tối đa bằng 0 (W = 0), trả về 0.

function knapsack_recursive(n, W, w[], v[]):
    if n == 0 or W == 0:
        return 0
    if w[n-1] > W: // Không thể chọn vật phẩm cuối cùng
        return knapsack_recursive(n-1, W, w, v)
    else:
        // Chọn tối đa giữa không chọn và chọn vật phẩm cuối
        return max(knapsack_recursive(n-1, W, w, v), 
                   v[n-1] + knapsack_recursive(n-1, W - w[n-1], w, v))


## 4. Ví dụ minh hoạ
### Ví dụ 1
**Input:**  
n = 3 (3 vật phẩm).  

W = 50 (trọng lượng tối đa).  

Trọng lượng: w = [10, 20, 30].  

Giá trị: v = [60, 100, 120].

**Output:**  
Tổng giá trị tối đa: 220.  

**Giải thích:**  
1. Xét vật phẩm 3 (w[2] = 30, v[2] = 120):
    Không chọn: Giá trị tối đa với n=2, W=50 → 160.
    Chọn: 120 + Giá trị tối đa với n=2, W=20 → 120 + 100 = 220.
2. Lấy max(160, 220) = 220.  
=> Kết quả: Chọn vật phẩm 2 và 3 (trọng lượng 20 + 30 = 50, giá trị 100 + 120 = 220).


### Ví dụ 2
**Input:**  
n = 4 (4 vật phẩm).
W = 10 (trọng lượng tối đa). 
Trọng lượng: w = [5, 4, 6, 3].  
Giá trị: v = [10, 40, 30, 50].

**Output:**  
Tổng giá trị tối đa: 90.

**Giải thích:**  
1. Xét vật phẩm 4 (w[3] = 3, v[3] = 50):
    Không chọn: Giá trị tối đa với n=3, W=10 → 40.
    Chọn: 50 + Giá trị tối đa với n=3, W=7 → 50 + 40 = 90.
2. Lấy max(40, 90) = 90.  
=> Kết quả: Chọn vật phẩm 2 và 4 (trọng lượng 4 + 3 = 7, giá trị 40 + 50 = 90).


### Ví dụ 3
**Input:**  
n = 2 (2 vật phẩm).  
W = 15 (trọng lượng tối đa).  
Trọng lượng: w = [12, 8].  
Giá trị: v = [120, 80].

**Output:**  
Tổng giá trị tối đa: 120.

**Giải thích:**  
1. Xét vật phẩm 2 (w[1] = 8, v[1] = 80):
    Không chọn: Giá trị tối đa với n=1, W=15 → 120.
    Chọn: 80 + Giá trị tối đa với n=1, W=7 → 80 + 0 = 80.
2. Lấy max(120, 80) = 120.  
=> Kết quả: Chọn vật phẩm 1 (trọng lượng 12, giá trị 120).




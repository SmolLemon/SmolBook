# Đường đi Euler

Cho một đồ thị \\(G = (V, E)\\), **đường đi Euler (Eulerian trail)** của đồ thị là một đường đi đi qua tất cả các cạnh đúng một lần. Tương tự, **chu trình Euler (Eulerian tour/circuit)** của một đồ thị là một đường đi đi qua tất cả các cạnh, và đỉnh bắt đầu và kết thúc của đường đi là cùng một đỉnh.

Dưới đây là ví dụ của một đường đi Euler trên đồ thị, với các số trên mỗi cạnh là thứ tự của các cạnh trên đường đi, đỉnh màu đỏ là đỉnh bắt đầu, đỉnh màu xanh là đỉnh kết thúc của đường đi:

<center>
<img src="../images/eulerian_path.png" alt="Đường đi Euler"/>
</center>

Còn đây là ví dụ của một chu trình Euler:

<center>
<img src="../images/eulerian_tour.png" alt="Chu trình Euler"/>
</center>

<br>

Ta gọi một đồ thị có chu trình Euler là **đồ thị Euler (Eulerian graph)**, đồ thị có đường đi Euler thì được gọi là **đồ thị nửa Euler (semi-eulerian graph)**.

## Xác định đường đi Euler

Để xác định đường đi Euler và chu trình Euler của một đồ thị liên thông, ta dựa vào [bậc](overview.md#Đỉnh-kề-cạnh-liền-thuộc-đỉnh) của các đỉnh trong đồ thị: 
- Nếu đồ thị có các đỉnh có bậc chẵn thì đồ thị tồn tại chu trình Euler. 
- Nếu đồ thị có hai đỉnh có bậc lẻ, các đỉnh còn lại có bậc chẵn thì đồ thị tồn tại đường đi Euler. 

Đối với đồ thị có hướng, ta xác định đường đi và chu trình Euler trong đồ thị như sau:
- Nếu đồ thị có bán bậc vào bằng bán bậc ra thì đồ thị tồn tại chu trình Euler. 
- Nếu đồ thị có một đỉnh có bán bậc vào lớn hơn bán bậc ra một đơn vị, một đỉnh có bán bậc ra lớn hơn bán bậc vào một đơn vị, các đỉnh còn lại có bán bậc vào bằng bán bậc ra thì tồn tại đường đi Euler. Đỉnh có bán bậc ra nhiều hơn là đỉnh đầu của đường đi Euler, còn đỉnh có bán bậc vào nhiều hơn là đỉnh cuối của đường đi.

### Bài toán \\(7\\) cây cầu

Sử dụng thông tin trên, ta có thể giải được **bài toán \\(7\\) cầu ở Königsberg** ở đầu chương [Lý thuyết đồ thị](.).

Ta hình dung thành phố Königsberg như một đồ thị, với hai bên bờ sông và hai hòn đảo là các đỉnh \\(A, C\\) và \\(B, D\\), những cây cầu là các cạnh. 

<center>
<img src="../images/Konigsberg_graph.png" alt="Königsberg biểu diễn dưới dạng đồ thị"/>
</center>

Ta thấy, các đỉnh \\(A, B, C, D\\) có bậc lần lượt là \\(3, 5, 3, 3\\) - không đỉnh nào có bậc chẵn.

Từ đây, ta kết luận rằng không tồn tại con đường đi qua tất cả các cây cầu chỉ một lần duy nhất. 

## Tìm đường đi Euler

### Thuật toán Fleury

### Thuật toán Hierholzer
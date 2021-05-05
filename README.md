GIỚI THIỆU VỀ TRÒ CHƠI
1.	Tên trò chơi: bắn gà

2.	Sử dụng thư viện SDL và ngôn ngữ C++

3.	Nguồn tham khảo: https://phattrienphanmem123az.com/lap-trinh-game-cpp và https://lazyfoo.net/SDL_tutorials/

4.	Luật chơi:

-	Trò chơi bao gồm các đối tượng: máy bay có thể bắn đạn, gà, trứng gà, hộp quà, đạn

-	Mỗi lượt chơi sẽ gồm 3 mạng

-	Sử dụng phím trái phải để điều khiển máy bay

-	Sử dụng chuột để bắn đạn

-	Nếu bắn trúng gà sẽ được cộng 10 điểm

-	Nếu máy bay va chạm với gà hoặc trứng gà sẽ mất một mạng và bị trừ 2 điểm

-	Nếu máy bay va chạm với hộp quà sẽ được cộng 10 điểm

-	Nếu hết mạng thì trò chơi sẽ kết thúc và show ra điểm mình đạt được

CÁC PHẦN VÀ CHỨC NĂNG CỦA TỪNG PHẦN TRONG TRÒ CHƠI

1.	COMMONFUNCION: chứa các hàm xử lí chung, các biến dùng nhiều lần trong toàn bộ chương 

trình

2.	BaseObject: là lớp cơ sở, chứa các hàm: lấy toạ độ, lấy kích thước, load ảnh.

3.	MainObject: quản lí điều khiển cũng như sự di chuyển của đối tượng chính là máy bay và lớp đạn đi kèm ( sự di chuyển của đạn, xoá đạn khi bắn trúng gà )

4.	ChickenObject: quản lí đối tượng quái là gà bao gồm ( random lên màn hình, reset lại ví trí khi bị bắn trúng…) cùng với đó là lớp trứng đi kèm  ( sự di chuyển, xoá 

trứng khi va chạm với máy bay)
 
5.	Bullet: quản lí đạn và trứng ( về thuộc tính là giống nhau) về toạ độ, về quỹ đạo di chuyển…
	
6.	Coin: quản lí  đối tượng hộp quà ( random lên màn hình và reset khi va chạm )
	
7.	Explosion: xử lí vụ nổ ( làm xuất hiện hiệu ứng vụ nổ khi có sự va chạm giữa gà hoặc trứng gà và máy bay )

8.	PlayPower: quản lí số lượt chơi ( số mạng ) trong 1 lần chơi
	
9.	Text: xử lí màu sắc, load đoạn text lên màn hình
	
10.	Souce: phần chính của project           


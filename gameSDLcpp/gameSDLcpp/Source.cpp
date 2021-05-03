
#include"COMMON_FUNCTION.h"
#include"MainObject.h"
#include"ChickenObject.h"
#include"Explosion.h"
#include"PlayerPower.h"
#include"Text.h"
#include"Menu.h"
#include"Coin.h"
using namespace std;
TTF_Font*g_font_text = NULL;
TTF_Font* g_font_text2 = NULL;

 
bool Init()
{
   if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	 return false;
  g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
  if (g_screen == NULL)
	return false;
  if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	  return false;
  //read file wav audio:
  g_sound_bullet[0] = Mix_LoadWAV("sound/laze.wav");
  g_sound_bullet[1] = Mix_LoadWAV("sound/sphere.wav");
  g_sound_exp[0] = Mix_LoadWAV("sound/exp1.wav");
  g_sound_exp[1] = Mix_LoadWAV("sound/exp2.wav");
  g_soundtrack = Mix_LoadWAV("sound/nen.wav");
  g_gift = Mix_LoadWAV("sound/soundgift.wav");
  if(g_sound_bullet[0] == NULL && g_sound_bullet[1] == NULL &&  g_sound_exp[0] == NULL &&  g_sound_exp[1] == NULL)
	  return false;
  if(TTF_Init() == -1)
	  return false;
  g_font_text = TTF_OpenFont("Lemon Friday.ttf", 20);
  g_font_text2 = TTF_OpenFont("k2.ttf",60);

  if(g_font_text == NULL || g_font_text2 == NULL)
	  return false;

  return true;
}

 
 
int main(int arc, char* argv[])
{  
	int bkg_y = 0;
    bool is_quit = false;
	if (Init() == false)
		return 0;

	
	
	
	//show background:
	g_bkground = SDL_CF::LoadImage("img/3.png");
	if (g_bkground == NULL)
		return 0;
		
	// make player power:
	PlayerPower player_power;
	player_power.Init();

	// make score:
	TextObject score_game;
	score_game.SetColor();
	
	//make time:
	TextObject time_game;
	time_game.SetColor();


	
	// show plane:
	MainObject plane_object;
	plane_object.SetRect(300,400);
	bool ret = plane_object.LoadImage("img/plane.png");
	if(!ret)
		return 0;
		
   
	//init explosion object:

	// between plane and chicken:
	ExplosionObject exp_main;
	ret = exp_main.LoadImage("img/exp_main.png");
	exp_main.set_clip();
	if(ret == false)
		return 0;

	//between egg and plane:
	ExplosionObject exp_egg;
	ret = exp_egg.LoadImage("img/exp_main.png");
	exp_egg.set_clip();
	if(ret == false)
		return 0;


   //random chicken:
	
	Chicken* p_chickens = new Chicken[NUM_CHICKEN];
	for(int t = 0; t < NUM_CHICKEN; t++)
	{
		Chicken* p_chicken = (p_chickens + t);
		if(p_chicken)
		{
			bool  ret = p_chicken->LoadImage("img/ck1.png");
			if(ret = false)
			{
				return 0;
			}
			int rand_y = rand()%400;
			if(rand_y > SCREEN_HEIGHT*0.5)
			{
				rand_y = SCREEN_HEIGHT*0.5;
			}
			p_chicken->SetRect(SCREEN_WIDTH + t*400, rand_y);
			p_chicken->set_x_val(3);
			//egg:
			Bullet* p_egg = new Bullet();
			p_chicken->Initegg(p_egg);
		}
	}

	//random coin:
	CoinObject* coins_ = new CoinObject[1];
	for(int k = 0; k < 1; k++)
	{
		CoinObject* coin_ = (coins_ + k);
		if(coin_)
		{
			bool  ret = coin_->LoadImage("img/gift.png");
			if(ret = false)
			{
				return 0;
			}
			int rand_x = rand()%400;
			if(rand_x > SCREEN_WIDTH*0.5)
			{
				rand_x = SCREEN_WIDTH*0.5;
			}
			coin_->SetRect( rand_x, SCREEN_HEIGHT + k*400);
			coin_->set_y_val(3);
		}
	}
	
	unsigned int die_num = 0; 
	unsigned int score = 0;
	
	Menu ret_menu ;
	if(ret_menu.ShowMenu(g_screen, g_font_text2) == 1)
	{ 
		is_quit = true;
	}
	if(is_quit != true)
		Mix_PlayChannel(-1, g_soundtrack, 5);
	
	while (!is_quit ) 
	{
		while (SDL_PollEvent(&g_even)) 
		{
			if (g_even.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			}
			plane_object.HandleInputAction(g_even, g_sound_bullet);
		}

	
	
		// move screen:
	
		bkg_y += 2;
		SDL_CF:: ApplySurface(g_bkground, g_screen, 0, bkg_y);
		SDL_CF:: ApplySurface(g_bkground, g_screen, 0, bkg_y - SCREEN_HEIGHT);
		if(bkg_y >= SCREEN_HEIGHT)
			bkg_y = 0;

		// show player power:
		player_power.Render(g_screen);
		
		//show and control plane:	
		plane_object.HandleMove();
		plane_object.Show(g_screen);
		plane_object.makebullet(g_screen);
	
		//run chicken:
		for(int tt = 0; tt < NUM_CHICKEN; tt++)
		{
			Chicken* p_chicken = (p_chickens + tt);
			if(p_chicken)
			{
				p_chicken->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				p_chicken->Show(g_screen);
				p_chicken->Makeegg(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
							
		// check collision between plane and chicken:
				bool is_col = SDL_CF::checkcollision(plane_object.GetRect(), p_chicken->GetRect());
				if(is_col)
				{   
					die_num ++;
						score -= 2;
					for(int ex = 0; ex < 4; ex++)
					{
						int x_pos = plane_object.GetRect().x + plane_object.GetRect().w*0.5 - WIDTH_EXPLOSION*0.5;
						int y_pos = plane_object.GetRect().y + plane_object.GetRect().h*0.5 - HEIGHT_EXPLOSION*0.5;
						exp_main.set_frame(ex);
						exp_main.SetRect(x_pos, y_pos);
						exp_main.ShowExp(g_screen);
						SDL_Delay(100);
						Mix_PlayChannel(-1, g_sound_exp[1], 0);
										
						//update screen:
						if(SDL_Flip(g_screen) == -1)
						return 0;
					}
					if(die_num <= 2)
					{
						SDL_Delay(2000);
						plane_object.SetRect(START_X_POS_PLANE, START_Y_POS_PLANE);
						player_power.decrease();
						player_power.Render(g_screen);
						if(SDL_Flip(g_screen) == -1)
						{
							delete[] p_chickens;
							SDL_CF:: CleanUp();
							SDL_Quit();
							return 0;
						}
					}
					
				}

				// check collision chicken and bullet:
				std:: vector<Bullet*> bullet_list = plane_object.Getbulletlist();
				for(int in = 0; in < bullet_list.size(); in++)
				{
					Bullet* p_bullet = bullet_list.at(in);
					if(p_bullet != NULL)
					{
						bool ret_col1 = SDL_CF::checkcollision(p_bullet->GetRect(), p_chicken->GetRect());
						if(ret_col1)
						{	
							score += 10;
							p_chicken->Reset(SCREEN_WIDTH + tt*400);
							plane_object.removebullet(in);
							Mix_PlayChannel(-1, g_sound_exp[0], 0);
						}
					}
				}

				// check collision between egg and plane:
				std:: vector<Bullet*> bullet_list2 = p_chicken->Getbulletlist();
				for(int in1 = 0; in1 < bullet_list2.size(); in1++)
				{
					Bullet* p_bullet = bullet_list2.at(in1);
					if(p_bullet != NULL)
					{
						bool ret_col2 = SDL_CF::checkcollision(p_bullet->GetRect(), plane_object.GetRect());
						if(ret_col2)
						{	
							die_num++;
							score -= 2;
							p_chicken->removeegg(in1);
							for(int ex2 = 0; ex2 < 4; ex2++)
							{
								int x_pos = plane_object.GetRect().x + plane_object.GetRect().w*0.5 - WIDTH_EXPLOSION*0.5;
								int y_pos = plane_object.GetRect().y + plane_object.GetRect().h*0.5 - HEIGHT_EXPLOSION*0.5;
								exp_egg.set_frame(ex2);
								exp_egg.SetRect(x_pos, y_pos);
								exp_egg.ShowExp(g_screen);
								SDL_Delay(50);
								Mix_PlayChannel(-1, g_sound_exp[1], 0);
								//update screen:
								if(SDL_Flip(g_screen) == -1)
									return 0;
							}
							if(die_num <= 2)
							{   
								SDL_Delay(2000);
								plane_object.SetRect(START_X_POS_PLANE, START_Y_POS_PLANE);
								player_power.decrease();
								player_power.Render(g_screen);
								if(SDL_Flip(g_screen) == -1)
								{
									delete[] p_chickens;
									SDL_CF:: CleanUp();
									SDL_Quit();
									return 0;
								}
							}
							
						}
					}
				}
			}
		}
		// run coin:
		for(int c = 0; c < 1; c++)
		{
			CoinObject* coin_ = (coins_ + c);
			if(coin_)
			{
				coin_->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				coin_->Show(g_screen);
				bool check = SDL_CF::checkcollision(plane_object.GetRect(), coin_->GetRect());
				if(check)
				{  
					score +=10;
					coins_->Resetgift(100);
					Mix_PlayChannel(-1, g_gift, 0);
				}

			}
		}

	//show score:
		string str_score = to_string(score);
		string text(" SCORE: ");
		text += str_score;
		score_game.SetText(text);
		score_game.SetRect(SCREEN_WIDTH*0.5, SCREEN_HEIGHT*0.01);
		score_game.CreateGameText(g_font_text, g_screen);
	
		if(die_num > 2)
		{
			
			g_end = SDL_CF::LoadImage("img/4.png");
			SDL_CF::ApplySurface(g_end, g_screen, 0, 0);
			TextObject endgame, n1;
			endgame.SetText("GAME OVER!");
			endgame.SetColor();
			endgame.SetRect(400, 200);
			endgame.CreateGameText(g_font_text2, g_screen);
			n1.SetText("SEE YOU LATER!");
			n1.SetColor();
			n1.SetRect(370, 400);
			n1.CreateGameText(g_font_text2, g_screen);
			TextObject total_score ;
			total_score.SetText(text);
			total_score.SetColor();
			total_score.SetRect(400,280);
			total_score.CreateGameText(g_font_text2, g_screen);
			
			
			
		}
	//update screen:
		if(SDL_Flip(g_screen) == -1)
		{
			delete[] p_chickens;
			SDL_CF:: CleanUp();
			SDL_Quit();
			return 0;
		}
	}
	delete [] p_chickens;
	SDL_CF:: CleanUp();

	
	SDL_Quit();
	return 1;
}

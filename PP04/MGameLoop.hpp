#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"
#include "Player.hpp"
#include "Object.hpp"

using namespace std;

namespace MuSeoun_Engine
{
    class MGameLoop
    {
    private:
        bool _isGameRunning;
        MConsoleRenderer cRenderer;
        chrono::system_clock::time_point startRenderTimePoint;
        chrono::duration<double> renderDuration;
        Player p;
        Object obj;
        string p1 = "P";
        string n = "n";
        string g = "";

    public:
        MGameLoop()
        {
            _isGameRunning = false;
        }
        ~MGameLoop()
        {

        }

        void Run()
        {
            _isGameRunning = true;
            Initialize();

            while (_isGameRunning)
            {
                Input();
                Update();
                Render();
            }
            Release();
        }
        void Stop()
        {
            _isGameRunning = false;
        }

    private:
        void Initialize()
        {

        }
        void Release()
        {

        }
        void Input()
        {
            if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
            {
                p.isKeyPressed();
            }
            else
            {
                p.isKeyUnpressed();
            }
            int x = rand() % 10;
            if (x <= 5)
            {
                obj.MoveObject();
            }
            else
            {
                obj.MoveFastObject();
            }

            if (obj.x <= 0)
            {
                obj.ResetObject();
            }
            if (obj.x == p.x && obj.y == p.y)
            {
                p1 = "";
                n = "";
                g = "GameOver";
            }
        }
        void Update()
        {

        }
        void Render()
        {

            cRenderer.Clear();
            cRenderer.MoveCursor(p.x, p.y);
            cRenderer.DrawString(p1);

            cRenderer.MoveCursor(obj.x, obj.y);
            cRenderer.DrawString(n);

            cRenderer.MoveCursor(20, 3);
            cRenderer.DrawString(g);

            cRenderer.MoveCursor(10, 10);

            renderDuration = chrono::system_clock::now() - startRenderTimePoint;
            startRenderTimePoint = chrono::system_clock::now();
            string fps = "FPS : " + to_string(1.0 / renderDuration.count());
            cRenderer.DrawString(fps);

            this_thread::sleep_for(chrono::milliseconds(20));
        }
    

    ////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;
    //int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
    //if (remainingFrameTime > 0)
    // this_thread::sleep_for(chrono::milliseconds(remainFrameTime));
    };
}
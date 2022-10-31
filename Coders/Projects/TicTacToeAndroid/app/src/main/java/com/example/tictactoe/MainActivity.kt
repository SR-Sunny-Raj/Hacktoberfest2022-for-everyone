package com.example.tictactoe

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.ImageView
import android.widget.TextView
import java.util.*

class MainActivity : AppCompatActivity() {

    //0-->x, 1--O,2-->null
    var activePlayer : Int = 0
    var gameState = intArrayOf(2,2,2,2,2,2,2,2,2)
    var winArray = arrayOf(intArrayOf(0,1,2), intArrayOf(3,4,5), intArrayOf(6,7,8), intArrayOf(0,3,6),
        intArrayOf(1,4,7), intArrayOf(2,5,8), intArrayOf(0,4,8), intArrayOf(2,4,6))
    var counter : Int = 0
    var gameActive : Boolean = true

    fun play(view: android.view.View)
    {

        val img : ImageView = view as ImageView
        var tapped:Int = Integer.parseInt(img.tag.toString())

        if(!gameActive) {
            gameReset(view)
            return
        }

        if(gameState[tapped]==2)
        {
            gameState[tapped] = activePlayer
            counter++
            img.translationX = -1000f

            if (counter == 9)
            {
                gameActive = false
            }

            if (activePlayer == 0)
            {
                img.setImageResource(R.drawable.x)
                activePlayer = 1
                var status = findViewById<TextView>(R.id.status)
                status.text = "    O's turn..! \n Tap to Play..!!"
            }
            else
            {
                img.setImageResource(R.drawable.o)
                activePlayer = 0
                var status = findViewById<TextView>(R.id.status)
                status.text = "    X's turn..! \n Tap to Play..!!"
            }
            img.animate().translationXBy(1000f).duration = 300;
        }
        var flag :Boolean = false
        for(win in winArray)
        {
            if(gameState[win[0]]!=2 && gameState[win[0]] == gameState[win[1]] && gameState[win[0]] == gameState[win[2]]) {
                flag = true

                gameActive = false

                if (flag && gameState[win[0]] == 0)
                    findViewById<TextView>(R.id.status).text = "    Hurrah..!\nX has won..!"
                if (flag && gameState[win[0]] == 1)
                    findViewById<TextView>(R.id.status).text = "    Hurrah..!\nO has won..!"
            }
        }

        if(counter==9 && !flag)
        {
            findViewById<TextView>(R.id.status).text = "Match Draw..!!"
        }
    }

    private fun gameReset(view:android.view.View)
    {
        gameActive = true
        activePlayer = 0
//        Arrays.fill(gameState,2)

        var i:Int = 0
        while(i<gameState.size)
            gameState[i++]=2

        counter=0

        findViewById<TextView>(R.id.status).text= "    X's turn..!\nTap to play.!!"
        findViewById<ImageView>(R.id.image0).setImageResource(0)
        findViewById<ImageView>(R.id.image1).setImageResource(0)
        findViewById<ImageView>(R.id.image2).setImageResource(0)
        findViewById<ImageView>(R.id.image3).setImageResource(0)
        findViewById<ImageView>(R.id.image4).setImageResource(0)
        findViewById<ImageView>(R.id.image5).setImageResource(0)
        findViewById<ImageView>(R.id.image6).setImageResource(0)
        findViewById<ImageView>(R.id.image7).setImageResource(0)
        findViewById<ImageView>(R.id.image8).setImageResource(0)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }
}
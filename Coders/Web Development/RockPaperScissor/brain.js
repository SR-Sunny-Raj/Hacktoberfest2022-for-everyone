let input_type = document.querySelectorAll("[data-selection]");
let final_res = document.querySelector("[final-res]");
let my_score = document.querySelector('[your-score]');
let robo_score = document.querySelector('[computer-score]');
let new_prac = document.querySelector('[data-make-des');

const winner_condition = [
    {
        name : "rock",
        emoji: "✊",
        beats: "scissor"
    },
    {
        name : "paper",
        emoji: "🖐",
        beats: "rock"
    },
    {
        name : "scissor",
        emoji: "✌️",
        beats: "paper"
    }
];


// decide the winner of the match
function is_winner(your_choice, comp_choice)
{
    return(your_choice.beats == comp_choice.name);
}

input_type.forEach(select => {
    select.addEventListener("click",e => {
        const sel = select.dataset.selection;
        const get_t = winner_condition.find(get_t=>get_t.name == sel);
        //console.log("Your selection: ");
        //console.log(get_t);
        const comp_sel = computer_select();
        const me_win = is_winner(get_t,comp_sel);
        const robo_win = is_winner(comp_sel,get_t);
        if(me_win)
            update_score(my_score);
        if(robo_win)
            update_score(robo_score);
        update(comp_sel,robo_win);
        update(get_t,me_win);
        //console.log("Computer_selection: ");
        //console.log(comp_sel);
        //console.log(sel);
    });
});

// to set the selection by the computer
function computer_select()
{
    const comp_sel = Math.floor(Math.random() * winner_condition.length);
    return winner_condition[comp_sel];
}

// update the winner
function update(choice, winner)
{
    const div = document.createElement("div");
    div.innerText = choice.emoji;
    div.classList.add("result");
    if(winner)
        div.classList.add("winner");
    else
        div.classList.add("loser");
    final_res.after(div);
}

// update the score

function update_score(score)
{
    score.innerText = parseInt(score.innerText) + 1;
}

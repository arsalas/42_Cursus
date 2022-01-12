const start = () => {
    const result = document.querySelector("#result");
    const note = document.querySelector("#note");
    const userDiv = document.querySelector("#user");
    
    let userCnt = `</div><h1>user: ${user}</h1>`;
    userCnt += ` <div>
    <img src="https://cdn.intra.42.fr/users/large_${user}.jpg" onerror="this.src='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAOEAAADhCAMAAAAJbSJIAAAAM1BMVEWzr7V+fIN7eYCxrbOVkpl/fYS2sriuqrCrp62cmZ+YlZynpKqCgIeFg4qLiI+PjJOgnaP2JHXtAAAGZUlEQVR4nO2diZqrIAxGXUHFhfd/2iu1M3VqbUESkvRynsD/SyQLEIoik8lkMplMJpPJZDKZ5CgH9Ueg4IRpY+3QNM1grdHfpVR3ppnb6i/t3JhOU38aAErbwakrjziVg9WiTamUaab2lbpfle3UGLn+qvvxpfGeTTn2Ir1Vdc34Wd5d5Nh00uyoimby1XfTODWFKI219XDPZ2e1NfVne6PMHChvYzZSzNi3lwSWZdtTf7oPqwFDHfRBJcCMynivoC8ljuwlXvbQH7h7ahNjwLsZG2oRb6gBBDqJfMNGA6DPwdaKC4QFHdVCLeU1A5TAVeJALeYVNnYV3dNaajkHlAXU57Dc4qIegRWO3GpGsFXmB26rzQCsz8FqtTHQPuoYDbWsB+paPfiJmc1io3ron3Cj6rlI1BOKwLKcuKynPZLAsmRSSXUYy8zG2FGLcyjAfPSZamDxJ6Lpc1CLK/AW0g0Oy2mNEwt/mOnrfZR05gGDxAakNXMOfV8KLdr/QB71Da4JVyMSu6lCdlLnprSrqcJ20nWtIY4X2CZcjUgr0CZQSNp2w8xJfxWS5qZIxf1fSEv9Gn+hWSMiZeLWJVFIWSQiJ6UbpKkp6F7FGaR7GFkhDIQKU4RD2joft4ORFWaFIAq//j/8/rU0x8MvUPj9eSl6L9FBWlsUKSpg0vpQLQkUktb439+nwW950ze9v75fmqDnPRF39dF/ROp9i+/feyo0dkScqfcPv38PGDv55nAcGvksBrW8/+E8DW7QJw73G5hG5GFCzCKRtjR8gJbXsLk6gxb16aP9HYV0XqHic28GqcIgrir+gHIQmscR6B8wDrMzOcb+w9ffeypq8Ltr9IeDnwBuf3O8lw97xZJB0XQAMj9lko8+o6Auq5cldffpFKCOBoPOxRkwjsrURTfUEN+1aXncdTolfkXluIruUZEHMicBQ7+6mD3FhVW2fUZ9uVwUM+5L6eXKgtMukmYo2qB5dDf7TdyXmL8o3ZdBM/fKXpIBb6hi8F9Vp0HWTME7Stv57WjPu/naWe4QU6XN8Ho666+8qh2MWH03lOr6eXo1x3QVN819J3c86wNVdLZvbjJ/Gae56W0n8u87Q+vOGNs7rDGd5tLOhuZ753lnMplMBga1h/pjALnpWaO9XfOaB721a9QXr7XWXWeHZSqrM8ppGWzXaSHNiz0uFx2W2aWin4qnNUmdnU5BOerqeLaZ3r/6cCwSp6mxhQif1Wu19NlyJ9ZcqyneGbkqzOBT1r+z5TwYtv6qin6G2Age556lxto0l3zzFVXVGGbL6+qeS5R3HjS2CytnVXaOei/gpcZxZnPoq4557+GtyJmFryqDeX9tYXDoZAD3zz3VSNwNrw3o+vJSY0voqipqM9SfhWpfWCW55+wgOgKm0cftPaia9Omq6pBCxInEObWnKhO8yRspcUrsqUlGfjxpTHk1oSYQ6CQmCxt1miBxZEkksU78Cz6o0oxX0OCH1gMkLgmiBpmLbuA7Kp2LbqA7KqWL3iUiOyrcUe7rYJ6RVuQWdFQLXnaTZDzbZyqsG1EqzewyD1qkHpXhInCViDIsI8nMYF9QYkbCgvczGJdO8B4Eugb4apOsJ+ML9Jy6BNOSQgG+B01S8r4HtuZn56MOSD9Ffg/oKnDvCOE/RHINuDFgmlrKKUCFFI+K4hVQVQabhPsIzJws9IlsMUDMdwF/yhgWiDqK60+4ET8qK81Q8uvEX/xO8s5KDNHDspgG+wexlSL4g+LwxD1Rnubxgzgi/0T+AuOWUwkmjDMi06rpmYgqinFGuud6dlqzLSr+Ul3eVOyoP92bi1Gfa2l/5HKxL+MvdLTXFCZ4gROKiy95yggVG5dGRrPskZ5xqXfKbSvmPRc2ali3Z45caNgY6m8OJNhNuXcvngl/jUbJCYYbwSGxk2XC1YiBmZuMynBPcJXIvcV2ZAoTKCrcb4QFfSUr3G8EuamU2ndPWB2c5NU/aKaQtCbBc2rwhLwMJae63xNS6TM8H+RDyBkiiSYMan4L6l/s8e9lyPwNQ35EJav4feD9Yin7fd8zvPeDhWxXHPHdwBCZlG74pqZCFxr/PX1hXbY9nh03lKeN0uD5gJLItHvDL/mW1kfc49dTTPKaOBZeB06V3N9w/RG9woVcJ/UsL7RohT7hQmjptOFTQEleSv0WU7Gl08axgPoHMQx4FI4yVMQAAAAASUVORK5CYII='"/>
    </div>`
    userDiv.innerHTML = userCnt;
    let content = '';
    data.forEach(el => {
        content += `
        <div class="exercice ${el.result ? `ok` : `ko`}">
            <div class="title">${el.name}</div>
            <div class="status">
                ${el.result ? `OK` : `KO`}
            </div>
        </div>
        `;
    });
    result.innerHTML = content;
    const calif = calcNote(data);
    let noteContent = '<div class="calification">';
    if (calif / data.length >= 0.5) {
        noteContent += `
           <span class="calification pass">RESULT: ${calif} / ${data.length}</span>
       `
    } else {
        noteContent += `
            <span class="calification fail">RESULT: ${calif} / ${data.length}</span>
       `
    }
    noteContent += '</div>'
    note.innerHTML = noteContent;
}

const calcNote = (data) => {
    let note = 0;
    data.forEach(el => {
        note += el.result;
    })
    return note;
}
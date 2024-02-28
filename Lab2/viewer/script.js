const actions = document.getElementById("actions");
const fileButton = document.querySelector(".file-button");
const imageContainer = document.getElementById("image-container");
const img = document.createElement("img");
document.addEventListener("click", function (event) {
    if (event.target !== fileButton && !actions.contains(event.target)) {
        actions.style.display = "none";
    }
});

function toggleActions() {
    actions.style.display = actions.style.display === "block" ? "none" : "block";
}

function displayImage(file) {
    img.src = URL.createObjectURL(file);

    imageContainer.style.left = '10%';
    imageContainer.style.top = '10%';
    imageContainer.innerHTML = "";
    imageContainer.appendChild(img);
}

document.getElementById("file").addEventListener("change", function (event) {
    const file = event.target.files[0];
    if (file) {
        displayImage(file);
    }
});

imageContainer.onmousedown = function (e) {
    let coords = getCoords(imageContainer)
    let shiftX = e.pageX - coords.left;
    let shiftY = e.pageY - coords.top;

    document.body.appendChild(imageContainer)
    moveAt(e);

    function moveAt(e) {
        imageContainer.style.left = e.pageX - shiftX + 'px';
        imageContainer.style.top = e.pageY - shiftY + 'px';
    }
    document.onmousemove = function (e) {
        moveAt(e)
    }
    imageContainer.onmouseup = function (){
        document.onmousemove = null;
        document.onmouseup = null;
    }
}

imageContainer.ondragstart = function (){
    return false;
}

function getCoords(el) {
    let box = el.getBoundingClientRect();
    return {
        top: box.top + window.scrollY,
        left: box.left + window.screenX
    };
}


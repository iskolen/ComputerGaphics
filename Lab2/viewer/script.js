document.addEventListener("click", function (event) {
    const actions = document.getElementById("actions");
    const fileButton = document.querySelector(".file-button");

    if (event.target !== fileButton && !actions.contains(event.target)) {
        actions.style.display = "none";
    }
});

function toggleActions() {
    const actions = document.getElementById("actions");
    actions.style.display = actions.style.display === "block" ? "none" : "block";
}

function displayImage(file) {
    const imageContainer = document.getElementById("image-container");

    const img = document.createElement("img");
    img.src = URL.createObjectURL(file);

    imageContainer.innerHTML = "";
    imageContainer.appendChild(img);

    imageContainer.style.display = "flex";
}

document.getElementById("file").addEventListener("change", function (event) {
    const file = event.target.files[0];

    if (file) {
        displayImage(file);
    }
});


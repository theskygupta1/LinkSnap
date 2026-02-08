async function shortenUrl() {
    const longUrl = document.getElementById("longUrl").value;
    const resultDiv = document.getElementById("result");

    if (!longUrl) {
        resultDiv.innerHTML = "❌ Please enter a URL";
        return;
    }

    try {
        const response = await fetch("http://localhost:8080/shorten", {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify({ url: longUrl })
        });

        const data = await response.json();

        resultDiv.innerHTML = `
            ✅ Short URL:<br/>
            <a href="${data.shortUrl}" target="_blank" style="color:#38bdf8;">
                ${data.shortUrl}
            </a>
        `;
    } catch (e) {
        resultDiv.innerHTML = "❌ Backend not running";
    }
}

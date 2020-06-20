'use strict';

(function(doc) {

    const uuidField = doc.getElementById('uuid');
    const baseUrl = 'http://localhost:8000';

    const configSubmitButton = doc.getElementById('submitConfig');
    const periodSubmitButton = doc.getElementById('submitPeriod');

    const logbookTable = doc.getElementById('logbook');
    const reportOutput = doc.getElementById('reportOutput');
    const barplotDiv = doc.getElementById('barplot');

    const colors = {
        1: '#6ec81d',
        2: '#006fd3',
        3: '#5400ac',
        4: '#b40983',
        5: '#e73131',
        6: '#ff9420',
    };

    const showColorTags = () => {
        for (let i = 1; i <= 6; i++) {
            const span = doc.getElementById(`colorSide${i}`);
            span.style.backgroundColor = colors[i];
        }
    };
    showColorTags();

    const loadConfig = () => {
        const uuid = uuidField.value;
        const endpoint = `${baseUrl}/config?identifier=${uuid}`;
        const prom = fetch(endpoint, {
            method: 'GET'
        });
        prom.then(response => response.json()).then(response => {
            for (let i = 1; i <= 6; i++) {
                let textField = doc.getElementById(`side${i}`);
                textField.value = response[i];
            }
        }).catch(err => window.alert(`Error fetching configuration: ${err}`));
    };
    loadConfig();

    configSubmitButton.addEventListener('click', () => {
        const sides = {};
        for (let i = 1; i <= 6; i++) {
            let textField = doc.getElementById(`side${i}`);
            let side = textField.value.trim();
            if (side == '') {
                window.alert(`Missing side configuartion for side ${i}.`);
                return true;
            }
            sides[i] = side;
        }
        const config = {
            'identifier': uuidField.value,
            'sides': sides
        };
        const endpoint = `${baseUrl}/config`;
        const prom = fetch(endpoint, {
            headers: {
                'Content-Type': 'application/json'
            },
            method: 'POST',
            body: JSON.stringify(config)
        });
        prom.then(response => {
            if (response.status == 201) {
                window.alert('Config was updated successfully');
            }
        }).catch(err => window.alert(`Error updating configuration: ${err}`));
    });

    periodSubmitButton.addEventListener('click', () => {
        const uuid = uuidField.value;
        const fromField = doc.getElementById('from');
        const toField = doc.getElementById('to');
        const from = fromField.value.trim();
        const to = toField.value.trim();
        if (from == '' || to == '') {
            window.alert('Both a from and a to date/time is needed.');
            return;
        }
        const reportEndpoint = `${baseUrl}/from-to-grouped`;
        const reportProm = fetch(reportEndpoint, {
            headers: {
                'Content-Type': 'application/json'
            },
            method: 'POST',
            body: JSON.stringify({
                'from': new Date(from).toUTCString(),
                'to': new Date(to).toUTCString(),
                'identifier': uuid
            })
        });
        const configEndpoint = `${baseUrl}/config?identifier=${uuid}`;
        const configProm = fetch(configEndpoint, {
            method: 'GET'
        });
        reportProm.then(response => response.json()).then(report => {
            configProm.then(response => response.json()).then(config => {
                flushChildren(logbookTable);
                logbookTable.append(createReportHeaderRow());
                for (const activity of report) {
                    logbookTable.append(createReportRow(activity, config));
                }
                createBarPlot(report, config);
                reportOutput.style.display = 'block';
            }).catch(err => window.alert(`Error fetching config: ${err}`));
        }).catch(err => window.alert(`Error fetching report: ${err}`));
    });

    const flushChildren = (node) => {
        let child = node.lastElementChild;
        while (child) {
            node.removeChild(child);
            child = node.lastElementChild;
        }
    };

    const createBarPlot = (report, config) => {
        flushChildren(barplotDiv);
        const margin = {top: 30, right: 30, bottom: 175, left: 100};
        const width = 800 - margin.left - margin.right;
        const height = 600 - margin.top - margin.bottom;
        const svg = d3.select('#barplot').append('svg')
            .attr('width', width + margin.left + margin.right)
            .attr('height', height + margin.top + margin.bottom)
            .append('g')
            .attr('transform', `translate(${margin.left}, ${margin.top})`);
        const barData = groupBySideSumDuration(report);
        const x = d3.scaleBand()
            .range([0, width])
            .domain(barData.map((d) => `${d['side']}: ${config[d['side']]}`))
            .padding(0.2);
        svg.append('g')
            .attr('transform', `translate(0, ${height})`)
            .call(d3.axisBottom(x))
            .selectAll('text')
            .attr('transform', 'translate(-10, +10)rotate(-90)')
            .style('text-anchor', 'end');
        const maxY = maxMinutes(barData);
        const y = d3.scaleLinear().domain([0, maxY]).range([height, 0]);
        svg.append('g').call(d3.axisLeft(y));
        svg.selectAll('mybar')
            .data(barData).enter().append('rect')
            .attr('x', (d) => x(`${d['side']}: ${config[d['side']]}`))
            .attr('y', (d) => y(d['minutes']))
            .attr('width', x.bandwidth())
            .attr('height', (d) => height - y(d['minutes']))
            .attr('fill', (d) => colors[d['side']]);
    };

    const maxMinutes = (barData) => {
        const durations = [];
        for (const item of barData) {
            durations.push(item['minutes']);
        }
        return Math.max(...durations);
    };

    const groupBySideSumDuration = (report) => {
        const durationBySide = new Map();
        for (let side = 1; side <= 6; side++) {
            durationBySide[side] = 0;
        }
        for (const activity of report) {
            const from = new Date(activity.from);            
            const to = new Date(activity.to);
            const diff = to - from;
            const side = parseInt(activity.side);
            durationBySide[side] += Math.floor(diff / 1000); // seconds
        }
        const grouped = [];
        for (const side in durationBySide) {
            grouped.push({'side': side, 'seconds': durationBySide[side]});
        }
        const groupedByMinutes = [];
        for (const bySeconds of grouped) {
            groupedByMinutes.push({
                'side': bySeconds['side'],
                'minutes': Math.ceil(bySeconds['seconds'] / 60)
            });
        }
        return groupedByMinutes;
    };

    const createReportHeaderRow = () => {
        const trHeader = doc.createElement('tr');
        const fromTh = doc.createElement('th'); 
        const toTh = doc.createElement('th'); 
        const periodTh = doc.createElement('th'); 
        const activityTh = doc.createElement('th'); 
        fromTh.textContent = 'From';
        toTh.textContent = 'To';
        periodTh.textContent = 'Duration';
        activityTh.textContent = 'Activity';
        trHeader.append(fromTh);
        trHeader.append(toTh);
        trHeader.append(periodTh);
        trHeader.append(doc.createElement('th')); // color
        trHeader.append(activityTh);
        return trHeader;
    };

    const createReportRow = (activity, config) => {
        const tr = doc.createElement('tr');
        const fromTd = doc.createElement('td');
        const toTd = doc.createElement('td');
        const periodTd = doc.createElement('td');
        const activityTd = doc.createElement('td');
        const colorTd = doc.createElement('td');
        colorTd.textContent = ' ';
        colorTd.classList.add('nopad');
        const colorSpan = doc.createElement('span');
        colorSpan.value = ' ';
        colorSpan.classList.add('color');
        const side = activity['side'];
        colorSpan.style.backgroundColor = colors[side];
        colorTd.append(colorSpan)
        const from = new Date(activity['from']);
        const to = new Date(activity['to']);
        fromTd.textContent = formatDate(from);
        toTd.textContent = formatDate(to);
        periodTd.textContent = formatDuration(activity['seconds']);
        const sideDescription = config[side];
        activityTd.textContent = `${side}: ${sideDescription}`;
        tr.append(fromTd);
        tr.append(toTd);
        tr.append(periodTd);
        tr.append(colorTd);
        tr.append(activityTd);
        return tr;
    }

    const formatDate = (date) => {
        const pad = (number, width) => {
            number += "";
            while (number.length < width) {
                number = "0" + number;
            }
            return number;
        };
        const year = pad(date.getFullYear(), 4);
        const month = pad(date.getMonth() + 1, 2);
        const day = pad(date.getDate(), 2);
        const hour = pad(date.getHours(), 2);
        const min = pad(date.getMinutes(), 2);
        const sec = pad(date.getSeconds(), 2);
        return `${year}-${month}-${day} ${hour}:${min}:${sec}`;
    };

    const formatDuration = (seconds) => {
        const hours = Math.floor(seconds / 3600);
        seconds -= hours * 3600;
        const minutes = Math.floor(seconds / 60);
        seconds -= minutes * 60;
        return `${hours}h ${minutes}m ${seconds}s`;
    };

}(document));

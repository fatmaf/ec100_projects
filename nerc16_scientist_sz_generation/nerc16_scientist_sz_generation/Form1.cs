using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace nerc16_scientist_sz_generation
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            for (int i = 0; i < 5; i++)
                map1.Columns.Add("x" + i.ToString(), i.ToString());
            //for (int j = 0; j < 10; j++)
                map1.Rows.Add(10);
            map1.AutoResizeColumns(); 

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;
using System.Diagnostics;

namespace WebApplication1
{
    public partial class WebForm6 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void sp_insert_Button_Click(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection(@"Data Source=TEST\MSSQLSERVER1; Initial Catalog= My_database; AttachDbFilename=C:\Program Files\Microsoft SQL Server\MSSQL14.MSSQLSERVER1\MSSQL\DATA\My_database.mdf;Integrated Security=True");
            con.Open();
            SqlCommand cmd = new SqlCommand("insert_into_cred", con);
            cmd.CommandType = CommandType.StoredProcedure;
            cmd.Parameters.Add(new SqlParameter("@Login_ID", TextBox1.Text));
            cmd.Parameters.Add(new SqlParameter("@Password", passwd.Text));
            int i = cmd.ExecuteNonQuery();

            con.Close();
            if (i != 0)
            {

                Debug.WriteLine("Data Saved");
            }

            Server.Transfer("WebForm1.aspx");
        }


    }
}